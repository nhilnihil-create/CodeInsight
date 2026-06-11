#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( i = c.begin(); i != c.end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
ll INF=1e18;
const int LIM=1e5+5,MOD=1e9+7;
ll min1(ll a,ll b)
{
    if(a<b)
        return a;
    else return b;
}
int main()
{
    fastio;
    

    int L;
    cin >> L;
    --L;
    int l = L, t = 0;
    for (; (1 << (t + 1)) - 1 <= l; ++t) {
    }
    const int N = t + 1;
    vector<ll > v1,v2,v3;
    forn(i, t) 
    {
        //ans.emplace_back(i + 1, i + 2, 0);
        v1.pb(i+1);
        v2.pb(i+2);
        v3.pb(0);
        v1.pb(i+1);
        v2.pb(i+2);
        v3.pb(1<<i);
        //ans.emplace_back(i + 1, i + 2, 1 << i);
    }
    l -= 1 << t;
    int base = 1 << t;
    while (l >= 0) 
    {
        for (t = 0; (1 << (t + 1)) - 1 <= l; ++t);
        //ans.emplace_back(t + 1, N, base);
        v1.pb(t+1);
        v2.pb(N);
        v3.pb(base);
        base += 1 << t;
        l -= 1 << t;
    }
    cout << N << ' ' << v1.size() << endl;
    forn(i,v1.size()) 
    {
        cout << v1[i] << ' ' << v2[i] << ' ' << v3[i] << endl;
    }
    return 0;
}