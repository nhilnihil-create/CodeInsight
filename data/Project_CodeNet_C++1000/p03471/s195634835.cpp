#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll n;
    cin >> n;
    ll val;
    cin >> val;

    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=n; j++)
        {

                if( i*10000 + j*5000 + (n-i-j)*1000 ==val && n-i-j>=0)
                {
                    cout << i << " " << j << " " << n  - i - j << endl;
             return 0;
                }
            }
        }

    cout<<"-1 -1 -1"<<endl;



}

