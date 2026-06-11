#include <bits/stdc++.h>
using namespace std;
using ld = long double;

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
  template<class T>void debug(vector<T>&v){int i=0;for(auto x:v)++i!=v.size()?show(x):showendl(x);} //vector出力
  template<class T>void debug(initializer_list<T>I){int i=0;for(auto x:I)++i!=I.size()?show(x):showendl(x);} //初期化子リスト出力
  template<class T>void debug(multiset<T>&M){int i=0;for(auto x:M)++i!=M.size()?show(x):showendl(x);} //multiset出力
}

int main(){
  cout<<fixed<<setprecision(15);
  ld N,K;cin>>N>>K;

  ld ans = 0;

  for(int i=1; i<=N; i++){
    int r = ceill(log2l(K/i));
    if(r<0)r=0;
    //DEBUG(i,r);
    ans += 1.0/(1<<r);
    //DEBUG(1.0/(1<<r));
  }
  ans /= N;
  cout<<ans<<endl;
}