#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 200005
#define maxm 500005
#define pii pair <int,int>
#define Task ""
using namespace std;
int n;
long double a[maxn],sum[maxn],x,ans = 50.0*maxc*maxc;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".inp", "r",stdin);
    cin >> n >> x;
    FOR(i,1,n) cin >> a[i],sum[i] = sum[i-1] + a[i];
    FOR(l,1,n)
    {
        int k = (n - 1) / l + 1;
        long double temp = 5.0*(sum[n] - sum[n-l]);
        FOR(j,2,k)
        {
            int q = max(0, n - j * l), w = n - (j - 1) * l;
            temp += 1.0*(2.0*j+1)*(sum[w] - sum[q]);
        }
        ans = min(ans,temp + 1.0*(l+n)*x);
    }
    cout << fixed << setprecision(0) << ans;
}
