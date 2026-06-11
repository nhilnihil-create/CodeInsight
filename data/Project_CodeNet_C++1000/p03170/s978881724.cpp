#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i-=-1)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define F first
#define S second
#define VanLoi "a"
#define maxn 100005
#define pii pair<int, int>
#define MOD 1000000007
#define B 107
#define gb(i,j) ((i >> j) & 1)
#define pb push_back
#define reset(x) memset(x, 0, sizeof(x))
#define Block 400
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

int n, k, a[maxn], l[maxn];

int get(int x) {
    if (x < a[1]) return 0;
    if (l[x] != -1) return l[x];
    int tg = 0;
    fi(i, 1, n) if (x >= a[i]) tg = max(tg, 1 - get(x - a[i]));
    return (l[x] = tg);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen(VanLoi".inp","r",stdin);
    freopen(VanLoi".out","w",stdout);
    #endif // ONLINE_JUDGE
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, k) l[i] = -1;
    if (get(k) == 1) cout << "First"; else cout << "Second";
}
