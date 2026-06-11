#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,h;
    cin >> n >> h;
    vector<int> a(n);
    vector<int> b(n);
    int maxa = 0;
    int minb;
    ll sum = 0;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        maxa = max(maxa,x);
        a[i] = x;
        b[i] = y;
    }
    ll ans = 0;
    sort(all(a),greater<int>());
    sort(all(b),greater<int>());
    rep(i,n){
        if(maxa >= b[i]) continue;
        sum += b[i];
        ans++;
        if(sum >= h){
            cout << i+1 << endl;
            return 0;
        }
    }
    int remain = h - sum;
    while(remain > 0){
        remain -= a[0];
        ans++;
    }
    cout << ans << endl;

    cout << endl;
    return 0;
}
