#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2010
#define inf 1e14
#define MOD 1000000007

int main()

{

    ll n;
    cin >> n;
    if(n==0)
    {

        cout << 0;
        return 0;
    }
    vector<ll> v;
    while(1)
    {

        if(n==0) break;
        v.pb(abs(n%2));
        if(n < 0)
        {

            ll x=abs(n)/2;
            if(abs(n)%2 != 0) x++;
            n=x;
        }
        else
        {

            n/=-2;
        }
    }
    reverse(v.begin(), v.end());
    for(ll i = 0; i < v.size(); i++) cout << v[i];
}
