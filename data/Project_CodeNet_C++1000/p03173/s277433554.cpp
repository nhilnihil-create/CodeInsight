#include <bits/stdc++.h>
#define BPhuong ""
#define maxn 505
#define maxm
#define fi(i,a,b) for(int i = a; i<= b; i++)
#define fid(i,a,b) for(int i = a; i>= b; i--)
#define se second
#define f first
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define bit(x, i) ((x>>i)&1)
#define oo 1e9
struct data{
    int x, y, z;
};
using namespace std;
int n, a[maxn], cl[maxn][maxn];
ll s[maxn], ans[maxn][maxn];
/*ll solve(int x, int y)
{
    if(x == y)
    {
        return 0;
    }
    if(cl[x][y]) return ans[x][y];
    cl[x][y] = 1;
    ans[x][y] = 1e18;
    fi(i, x, y-1)
    {
        ans[x][y] = min(ans[x][y], solve(x, i) + solve(i+1, y) + s[y] - s[x-1]);
    }
    return ans[x][y];
}*/
void nhap(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    //freopen(BPhuong".inp","r",stdin);
    //freopen(BPhuong".out","w",stdout);
    cin >> n;
    fi(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        fid(j, i-1, 1)
        {
            ans[j][i] = 1e18;
            fi(t, j, i-1)
            {
                ans[j][i] = min(ans[j][i], ans[j][t] + ans[t+1][i] + s[i] - s[j-1]);
            }
        }
    }
    cout << ans[1][n];
}

void xuli(){
   // cout << solve(1, n);

}

int main(){
    nhap();
    xuli();
}
