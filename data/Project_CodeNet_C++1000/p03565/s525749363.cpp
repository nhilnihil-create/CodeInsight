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


int main(){
    string S, T; cin >> S >> T;
    int sn = S.size();
    int tn = T.size();

    //reverse(S.begin(),S.end());
    //reverse(T.begin(),T.end());
    int index = -1;
    rep(i,sn){
        if (i+tn-1 >= sn) break;
        bool isOK = true;
        rep(j,tn){
            if (S[i+j] == '?' || S[i+j] == T[j]) continue;
            isOK = false;
            break;
        }
        if(isOK) index = i; 
    }

    if (index == -1){
        cout << "UNRESTORABLE" << endl;
    }
    else{
        rep(i,tn){
            S[index+i] = T[i];
        }
        rep(i,sn){
            if (S[i] == '?'){
                S[i] = 'a';
            }
        }
        //reverse(S.begin(), S.end());
        cout << S << endl;
    }
    
}