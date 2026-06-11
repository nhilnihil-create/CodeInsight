#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P; 
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n){
        ll tmp;
        cin >> tmp;
        a[i] = tmp-i-1;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    ll chuo;
    if (n%2){
        chuo = a[n/2];
    }else{
        chuo = (a[n/2] + a[(n-1)/2])/2;
    }
    rep(i, n){
        ans += abs(a[i] - chuo);
    }
    cout << ans << endl;
    return 0;
}