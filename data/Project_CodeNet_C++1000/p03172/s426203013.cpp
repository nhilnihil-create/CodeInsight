#include <bits/stdc++.h>
#define BPhuong "main"
#define maxn 100005
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
int n, f[maxn], mod, k;
void add(int& a, int b)
{
    a+=b;
    if(a>=mod) a-=mod;
}
void release(int& a, int b)
{
    a-=b;
    if(a < 0) a+=mod;
}
void nhap(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    //freopen(BPhuong".inp","r",stdin);
    //freopen(BPhuong".out","w",stdout);
    cin >> n >> k;
    mod = 1e9+7;
}

void xuli(){
    f[0] = 1;
    fi(i, 1, n)
    {
        int a;
        vector <int> sum(k+1);
        cin >> a;
        fid(j, k, 0)
        {
            int cnt = f[j];
            int l = j+1;
            int r = j + min(k-j, a);
            if(l<=r)
            {
                add(sum[l], cnt);
                if(r+1 <= k) release(sum[r+1], cnt);
            }
        }
        int pre = 0;
        fi(j, 0, k)
        {
            add(pre, sum[j]);
            add(f[j], pre);
        }
    }
    cout << f[k];
}

int main(){
    nhap();
    xuli();
}
