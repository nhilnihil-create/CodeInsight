#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

int ans = 100000000;

int main(){
    int N, K; cin >> N >> K;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    map<int, int> counter;
    rep(i,N){
        counter[A[i]]++;
    }
    vector<int> char_count;
    int count = 0;
    for(auto c : counter){
        char_count.push_back(c.second);
        count++;
    }
    sort(char_count.begin(), char_count.end());

    ll ans = 0;
    rep(i,char_count.size()-1){
        if (count <= K) break;

        ans += char_count[i];
        count--;        
    }

    cout << ans << endl;


}
