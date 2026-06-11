# include <iostream>
# include <cstring>
using namespace std;

int N;
string S;
long long counting[100005];
long long ans=1;
int order;
int n;

int main()
{
    cin>>N;
    cin>>S;

    for (int i=0; i<N; i++)
    {
        order=S[i]-'a';
        counting[order]++;
    }

    for (int i=0; i<26; i++)
    {
        if (counting[i]>0)
        {
            n=(counting[i]+1)%1000000007;
            ans=(ans*n)%1000000007;
        } 
    }

    ans=(ans-1)%1000000007;

    cout<<ans<<endl;
}