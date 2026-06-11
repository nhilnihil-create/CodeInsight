#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
//https://drken1215.hatenablog.com/entry/2019/05/12/004500
ll n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    ll ans=0;
    for(ll i=1;i*i<=n;i++){
        if((n-i)%i==0&&(n-i)/i>i)ans+=(n-i)/i;
    }
    cout<<ans<<endl;
    return 0;
}