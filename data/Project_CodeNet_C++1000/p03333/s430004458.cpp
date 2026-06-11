#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define faster_io() ios_base::sync_with_stdio(false)
#define pb push_back
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define vii vector<pair<int,int>>

const int INF = 1000000005;
const ll INFLL = 1000000000000000002ll;
const ll MOD = 1000000007;

inline ll min(ll a, ll b, ll c){return min(min(a,b),c);}
inline ll min(ll a, ll b, ll c, ll d){return min(min(min(a,b),c),d);}
inline ll max(ll a, ll b, ll c){return max(max(a,b),c);}
inline ll max(ll a, ll b, ll c, ll d){return max(max(max(a,b),c),d);}

// -------------------------------------------------------------------------------------------------------------

int N, A[100005], B[100005];
multiset<int> L;
multiset<int,greater<int>> R;

ll solve(int t)
{
    L.clear(), R.clear();
    f(i,1,N) L.insert(B[i]);
    f(i,1,N) R.insert(A[i]);
    int x = 0;
    ll ret = 0;
    f(times,1,N)
    {
        if(t == 0)
        {
            int nx = *L.begin();
            L.erase(L.begin());
            //cout << x << "->" << nx << "\n";
            if(nx < x) ret += x-nx;
            x = min(x, nx);
        }
        else
        {
            int nx = *R.begin();
            R.erase(R.begin());
            //cout << x << "->" << nx << "\n";
            if(nx > x) ret += nx-x;
            x = max(x, nx);
        }

        t ^= 1;
    }
    return ret + abs(x);
}

int main()
{
    cin >> N;
    f(i,1,N) cin >> A[i] >> B[i];
    ll ans = solve(0);
    ll ans2 = solve(1);
    cout << max(ans, ans2);
}
