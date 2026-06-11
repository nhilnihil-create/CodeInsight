#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define TTT "Stones"
#define maxn 105
#define maxk 100005
using namespace std;
int n, k, a[maxn];
int f[maxk][2], cl[maxk][2];
int cal(int x, int tt)
{
    if(x < a[1]) return 0;
    if(cl[x][tt]) return f[x][tt];
    cl[x][tt] = 1;
    f[x][tt] = 0;
    fi(i, 1, n)
    if(x - a[i] >= 0 && cal(x - a[i], 3 - tt) == 0)
    {
        f[x][tt] = 1;
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen(TTT".inp", "r", stdin);
    freopen(TTT".out", "w", stdout);
    #endif // ONLINE_JUDGE
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    if(cal(k, 1)) cout << "First"; else cout << "Second";
}
