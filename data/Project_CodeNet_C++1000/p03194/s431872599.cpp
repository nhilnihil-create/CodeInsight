#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;


int main()
{
    ll N, P;
    cin>>N>>P;

    ll ans = 1;

    if(N==1){
        cout<<P<<endl;
        return 0;

    }
    else if(P==1)
    {
        cout<<1<<endl;
        return 0;
    }

    for(ll i=2; i*i<=P; ++i)
    {
        ll count = 0;
        while(P%i==0)
        {
            count++;
            if(count==N)
            {
                ans*=i;
                count=0;
            }
            P/=i;

        }

    }

    cout<<ans<<endl;


    return 0;
}

