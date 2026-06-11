//bad_bat
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

bool ispal(ll x)
{

    string ss;
    while(1)
    {

        if(x==0) break;
        char c = '0'+(x%10);
        x/=10;
        ss.pb(c);
    }
    string kk = ss;
    reverse(all(ss));
    return (ss==kk);
}

int main()

{

    ll n, m;
    cin >> n >> m;
    if(n==2 || m==2)
    {

        cout << 0;
    }
    else if(n==1 || m==1)
    {
        if(n==1&&m==1) cout << 1;
        else cout << max(n,m)-2;
    }
    else cout << (n*m)-(n*2)-(m*2)+4;
}
