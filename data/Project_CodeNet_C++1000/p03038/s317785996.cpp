#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n, m;
    cin >> n >> m;
    VL a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    VP ope(m);
    rep(i,m){
        cin >> ope[i].second >> ope[i].first;
    }
    sort(rall(ope));
    int left = 0, i = 0;
    while(left < n){
        if (ope[i].first < a[left]) {
            left++;
            continue;
        }
        while(ope[i].second){
            a[left] = ope[i].first;
            left++;
            ope[i].second--;
            if (left >= n || a[left] > ope[i].first) break;
        }
        i++;
    }
    ll ans = 0;
    rep(i,n) ans += a[i];
    cout << ans << endl;
    return 0;
}