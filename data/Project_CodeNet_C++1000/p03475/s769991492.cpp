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
    int N; cin >> N;
    vector<int> C(N-1), S(N-1), F(N-1);
    rep(i,N-1){
        cin >> C[i] >> S[i] >> F[i];
    }

    for(int i = 0; i < N-1; i++){
        int current_time = 0;
        for (int j = i; j < N-1; j++){
            if (current_time <= S[j]){
                current_time = S[j];
            }
            else{
                if ((current_time - S[j]) % F[j] != 0){
                    current_time += F[j] - (current_time % F[j]);
                } 
            }
            current_time += C[j];
        }
        cout << current_time << endl;
    }
    cout <<  0 << endl;

}