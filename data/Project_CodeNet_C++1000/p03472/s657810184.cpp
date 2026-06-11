#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    ll N, H; cin >> N >> H;
    vector<ll> A, B;
    A = B = vector<ll>(N,0);
    rep(i,N){
        cin >> A[i] >> B[i];
    }

    // aの最大値を算出
    ll max_a = 0;
    rep(i,N){
        max_a = max(max_a, A[i]);
    }
    
    // bの降順でソート
    sort(B.begin(), B.end(), greater<ll>());
    
    ll ans = INF;
    rep(i,N){
        H -= B[i];
        ll a_count = 0;
        if (H > 0){
            a_count = (H+(max_a-1))/ max_a;
        }
        ans = min(ans, a_count+i+1);
    }

    cout << ans << endl;

}