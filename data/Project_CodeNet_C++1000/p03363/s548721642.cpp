# include <iostream>
# include <map>
using namespace std;

int N;
int A[200005];
long long prefixsum[200005];
map <long long, long long> frequency;
long long ans=0;

int main()
{
    frequency[0]=1;

    cin>>N;

    for (int i=1; i<=N; i++)
    {
        cin>>A[i];
    }

    for (int i=1; i<=N; i++)
    {
        prefixsum[i]=prefixsum[i-1]+A[i];

        ans=ans+frequency[prefixsum[i]];

        frequency[prefixsum[i]]++;
    }

    cout<<ans<<endl;
}