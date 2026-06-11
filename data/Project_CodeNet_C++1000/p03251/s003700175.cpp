#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
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
#define inf 1e9
#define MOD 1000000007

int main()
{

    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll mx=-inf, my=inf;
    for(ll i = 0; i < n; i++)
    {

        ll z;
        cin >> z;
        mx = max(mx, z);
    }
    for(ll i = 0; i < m;i++)
    {

        ll z;
        cin >> z;
        my = min(z,my);
    }
    bool tf = 0;
    for(ll i = x+1; i <= y; i++)
    {

        if(i > mx && my>=i)
        {

            tf=1;
            break;
        }
    }
    if(tf) cout << "No War";
    else cout << "War";
}
