#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
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

int main(){

    int N; cin >> N;

    vector<int> depos;

    int tmp = 1;
    while (N >= tmp){
        depos.push_back(tmp);
        tmp*=6;
    }

    tmp = 9;
    while (N >= tmp){
        depos.push_back(tmp);
        tmp*=9;
    }

    //vector<vector<int>> dp(depos.size()+1,vector<int>(N+1,100000000));
    vector<int> dp(N+1,100000000);
    //dp[0][0] = 0;
    dp[0] = 0;

    //cout << depos.size() << endl;

    rep(i,depos.size()){
        rep(j, N){
            if (j+depos[i] > N) continue;
            dp[j+depos[i]] = min(dp[j+depos[i]], dp[j]+1);
        }
    }

    cout << dp[N] << endl;


}