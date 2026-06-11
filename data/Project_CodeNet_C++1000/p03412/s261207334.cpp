#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

const ll mod = 1e9+7;

// void chmod(ll &M){
//     if(M >= mod) M %= mod;
//     else if(M < 0){
//         M += (abs(M)/mod + 1)*mod;
//         M %= mod;
//     }
// }

int main(){
    int N; cin >> N;
    vector<int> a(N), b(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    for(int i=0; i<N; ++i) cin >> b[i];

    int ans = 0;

    for(int k=28; k>=0; --k){
        int T = 1<<k;
        for(int i=0; i<N; ++i) {
            a[i] %= 2*T;
            b[i] %= 2*T;
        }
        sort(b.begin(), b.end());
        ll cnt = 0;
        for(int i=0; i<N; ++i){
            cnt += lower_bound(b.begin(), b.end(), 2*T-a[i]) - lower_bound(b.begin(), b.end(), T-a[i]);
            cnt += lower_bound(b.begin(), b.end(), 4*T-a[i]) - lower_bound(b.begin(), b.end(), 3*T-a[i]);
        }
        if(cnt%2 == 1) ans += T;
    }

    cout << ans << endl;
}