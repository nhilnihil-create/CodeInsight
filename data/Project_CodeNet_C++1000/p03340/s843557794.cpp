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
    int n;
    cin >> n;
    VL a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    int left = 0, right = 0;
    VI d2(30);
    while(right < n){
        rep(i, 30) d2[i] += ((a[right] >> i) & 1);
        bool ok = true;
        rep(i, 30) if (d2[i] >= 2) ok = false;

        if (!ok){
            while(left < right){
                rep(i,30) d2[i] -= ((a[left] >> i) & 1);
                left++;
                bool ch = true;
                rep(i, 30) if (d2[i] >= 2) ch = false;
                if (ch) break;
            }
        }

        ans += (right - left + 1LL);
        right++;
    }
    cout << ans << endl;
    return 0;
}