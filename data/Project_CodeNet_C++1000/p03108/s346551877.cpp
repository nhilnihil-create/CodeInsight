#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
const int LIMIT = 1e9 + 7;
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()

namespace /* debug */{
  #define DEBUG(...) do{cout<<#__VA_ARGS__<<" = ";debug(__VA_ARGS__);}while(0) //変数
  #define ldebug(...) do{cout<<"["<<setw(3)<<__LINE__<<"] ";debug(__VA_ARGS__);}while(0) //行数
  #define lDEBUG(...) do{cout<<"["<<setw(3)<<__LINE__<<"] "<<#__VA_ARGS__<<" = ";debug(__VA_ARGS__);}while(0) //変数, 行数
  template<class T>void show(T&x){cout<<x<<" ";} //出力
  template<class T>void showendl(T&x){cout<<x<<endl;} //出力改行
  template<class P,class Q>void show(pair<P,Q>&x){cout<<"("<<x.first<<", "<<x.second<<") ";} //pair出力
  template<class P,class Q>void showendl(pair<P,Q>&x){cout<<"("<<x.first<<", "<<x.second<<")"<<endl;} //pair出力改行
  template<class H>void debug(H&&h){showendl(h);} //引数1つ
  template<class H,class...Ts>void debug(H&&h,Ts&&...ts){show(h);debug(forward<Ts>(ts)...);} //可変引数
  template<class T>void debug(vector<T>&vt){int i=0;for(auto x:vt)++i!=vt.size()?show(x):showendl(x);} //vector出力
  template<class T>void debug(initializer_list<T>init){int i=0;for(auto x:init)++i!=init.size()?show(x):showendl(x);} //初期化子リスト出力
}

template<class T>
class UnionFind {
  vector<T> par;
public:
  UnionFind(T n) : par(n, -1) { }
  void init(T n) { par.assign(n, -1); }
  
  T root(T x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }
  
  bool isSame(T x, T y) {
    return root(x) == root(y);
  }
  
  bool merge(T x, T y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  
  T size(T x) {
    return -par[root(x)];
  }
};


int main(){
	ll N,M;cin>>N>>M;
  vi A(M), B(M);
  rep(i,M){
    cin>>A[i]>>B[i];
    A[i]--; B[i]--;
  }

  UnionFind<ll> uf(N);

  vector<ll> ans(M+1);
  ans[M] = N*(N-1)/2; //ここでオーバーフローするので "ll N"
  for(int i=M-1; i>=0; i--){
    ll a = uf.size(A[i]);
    ll b = uf.size(B[i]);
    if( !uf.merge(A[i], B[i]) ){
      ans[i] = ans[i+1];
    }else{
      ans[i] = ans[i+1] - (a*b);
    }
  }

  for(int i=1; i<=M; i++)cout<<ans[i]<<endl;
}