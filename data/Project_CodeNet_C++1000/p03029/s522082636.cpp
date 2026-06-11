#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define LIMIT 1000000007 //10^9+7
/* 一括cin */
template<class H>
void CIN(H& h){cin>>h;}
template<class H, class... T>
void CIN(H &h, T&... t){cin>>h;CIN(t...);}
/* デバッグ */
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

int main(){
  int a,p;CIN(a,p);
  debug((a*3+p)/2);
}