#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,s,e) for(int i=s;i<=e;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX (int)1e9 + 99
#define maxof(a,b,c) max(a,max(b,c))
#define minof(a,b,c) min(a,min(b,c))
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pa pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define bitcnt(x) __builtin_popcount(x)
#define gcd(a,b) __gcd(a,b)
#define all(x) (x).begin(),(x).end()
#define ts(x) to_string(x)
#define set0(x) memset(x, 0, sizeof(x))
const double pi = 3.14159265358979323846;
template<class T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is;}
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) {if (!v.empty()) {os << v.front();for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];} return os;}
const int N=50010;

void solve()
{
    int n,k;
    cin>>n>>k;

    vi a(n);
    cin>>a;

    vector<bool> dp(k+1, false);

    for(int i = 0; i<=k;i++)
    {
        for(int j: a)
        {
            if(i >= j && !dp[i-j])
                dp[i] = true;
        }
    }

    cout<<(dp[k]?"First":"Second");
}

int main()
{
    fastio;
    
    int t=1;
    
    rep(i,t)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}

