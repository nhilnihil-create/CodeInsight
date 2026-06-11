#include "bits/stdc++.h"
#define _USE_MATH_DEFINES
#include <math.h>
 
using namespace std;
 
using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
using VVVLL = std::vector<VVLL>;
using LD = long double;
using VLD = std::vector<LD>;
using VVLD = std::vector<VLD>;
using VVVLD = std::vector<VVLD>;
 
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }

//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) {LL i=0; for(auto (a): v ){   cerr <<i << " : "<<  a << endl; i++;}}
#define PRINTSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl
#define cmax(a,b) {if(a<b){a=b;}}
#define cmin(a,b) {if(a>b){a=b;}}
#define EACH(a,A) for(auto a: A)
//#define cmax(a,b) a = (a>b ? a:b)
//#define cmin(a,b) a = (a<b ? a:b) 
//cin,cout高速化のおまじない＋桁数指定
inline VLL cinvll(LL N){
  VLL A(N);
  REP(i,N){
    cin >> A[i];
  }
  return move(A);
}
struct Fast{
	Fast(){
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast;



void func(){
  string S;
  cin >> S;
  string T = "AKIHABARA";
  string U;


  bool ok = true;
  LL j=0;
  for(LL i=0;i<T.length();++i){
    //cerr << T[i]<< " " << S[j]<< endl;
    if(T[i] ==  S[j]){
      j++;

    }
    else if (T[i]=='A'){
    }
    else{
      ok=false;
    }
  }
  if(j!=S.length()){
     ok=false;
  }
  if(ok){
    cout << "YES";
  }
  else{
    cout << "NO";
  }



} 

int main()
{
  func();
  return 0;
}
 