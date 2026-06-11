#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

int main(){
    int N, M; cin >> N >> M;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    vector<int> cum(N+1,0);
    rep(i,N){
        cum[i+1] = (cum[i] + A[i]) % M;
    }

    map<int, int> counter;
    ll ans = 0;
    rep(i,N+1){
        ans += counter[cum[i]];
        counter[cum[i]]++;
    }

    cout << ans << endl;
}