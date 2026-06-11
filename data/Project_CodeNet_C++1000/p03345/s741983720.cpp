# include <iostream>
# include <cmath>
using namespace std;

long long A, B, C, K;
long long limit=1000000000000000000ll;
long long ans;

int main()
{
    cin>>A>>B>>C>>K;
    if (K%2==0)
    {
        ans=A-B;
    }

    else
    {
        ans=B-A;
    }

    if (abs(ans)>limit)
    {
        cout<<-1<<endl;
    }

    else
    {
        cout<<ans<<endl;
    }
}