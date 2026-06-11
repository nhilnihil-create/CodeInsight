#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j,k,l;

    ll sum=0LL,a,m,x;
    cin >> n >> m;
    cnt[0] = 1LL;
    ll ans = 0LL;
    for(i=1;i<=n;i++)
    {
        cin >> a;
        sum += a;
        x = sum%m;
        ans += cnt[x];
        cnt[x]++;

    }
    cout << ans << endl;
}
