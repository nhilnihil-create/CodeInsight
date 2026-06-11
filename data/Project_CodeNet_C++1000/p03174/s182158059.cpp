#include <bits/stdc++.h>
#define BPhuong ""
#define maxn 22
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
int n, a[maxn][maxn], f[22][2100000], mod;
void nhap(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    //freopen(BPhuong".inp","r",stdin);
    //freopen(BPhuong".out","w",stdout);
    cin >> n;
    fi(i, 0, n-1)
        fi(j, 0, n-1) cin >> a[i][j];
}

void xuli(){
    f[0][0] = 1; mod = 1e9 + 7;
    fi(i, 0, n-1)
    {
        if(a[0][i])
        {
            f[0][(1 << i)] = 1;
        }
    }
    fi(i, 1, n-1)
    {
        fi(j, 0, (1<<n)-1)
        {
            int cnt = j;
            if(f[i-1][j] == 0) continue;
            fi(k, 0, n-1)
            {
                if(a[i][k] && !bit(cnt, k))
                {
                    f[i][cnt + (1<<k)] += f[i-1][cnt];
                    f[i][cnt + (1<<k)] %= mod;
                }
            }
        }
    }
    cout << f[n-1][(1 << n)-1];
}

int main(){
    nhap();
    xuli();
}
