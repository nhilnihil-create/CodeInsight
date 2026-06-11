
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)


int main()
{
    optimize();


        ll n;
        cin>> n;

        ll a[n], mx[n], mn[n];

        for(ll i=0; i<n; i++)
            cin>> a[i];

            if(n==2)
            {
                cout<< max(a[0], a[1]);
                nl;
                return 0;

            }


        ll c=0;

        mx[0] = a[0];
        mn[n- 1] = a[n- 1];

        for (ll i = 1; i< n; i++)
            mx[i] = __gcd (mx[i- 1], a[i]);


        for (ll i = n- 2; i>= 0; i--)
            mn[i] = __gcd(mn[i + 1], a[i]);

            ll t, res= 1;
            res= max(mx[n-2], mn[1]);


        for(ll i=1; i<n; i++)
        {

            t= __gcd(mn[i], mx[i-2]);
            t= max(t, __gcd(t, a[i]));
            res= max(t, res);
        }

        cout<< res;
        nl;


    return 0;
}


