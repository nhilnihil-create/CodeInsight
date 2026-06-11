
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//a,b,c,d,eのうち一番小さい人数に全ての交通手段を合わせても変わらない
int main(){
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    //{}で配列にすると2つ以上もminで扱える
    ll minmove = min({a,b,c,d,e});
    ll ans = ((n+minmove-1)/minmove) +4;
    cout << ans << endl;


}