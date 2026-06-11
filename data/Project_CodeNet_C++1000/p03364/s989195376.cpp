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
using BL = bool;
using VBL = std::vector<BL>;
using VVBL = std::vector<VBL>;
using VVVBL = std::vector<VVBL>;


template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }

//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define REPM(i,n,m) for(LL (i)=m;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) {LL i=0; for(auto (a): v ){   cerr <<i << " : "<<  a << endl; i++;}}
//#define PRINTSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl

template<class T> 
void PRINTSP(vector<T> v, size_t w=3){
  for(auto (a): v ) {cerr <<setw(w)<< a << " ";} cerr << endl;
} 

template<typename TTT>
vector<LL> arg_sort(vector<TTT> A, bool ascend = true) {
  vector<LL> index(A.size());
  iota(index.begin(), index.end(), 0);
  if (ascend) {
    std::sort(index.begin(), index.end(), [&A](TTT i1, TTT i2) {
      return A[i1] < A[i2];
      });
  }
  else {
    std::sort(index.begin(), index.end(), [&A](TTT i1, TTT i2) {
      return A[i1] > A[i2];
      });
  }

  return index;
}

struct UinonFindTree {
private:
  vector<LL> UFT;
public:
  UinonFindTree(LL N) {
    UFT.resize(N);
    for (LL i = 0; i < N; i++) {
      UFT[i] = -1; 
    }
  }

  LL root(LL i) { 
    if (UFT[i] < 0) {
      return i;
    }
    else {
      LL j = root(UFT[i]);
      UFT[i] = j;
      return j;
    }
  }

  bool same(LL i, LL j) {
    return (root(i) == root(j));
  }

  void unite(LL i, LL j)
  {
    LL root_i = root(i);
    LL root_j = root(j);
    if (root_i != root_j) {
      if (size(root_i) < size(root_j)) {
        swap(root_i, root_j);
      }
      UFT[root_i] += UFT[root_j];
      UFT[root_j] = root_i;
    }
  }

  LL size(LL i) {
    return -UFT[root(i)];
  }

  LL get_root_num() {
    set<LL> roots;
    for (LL i = 0; i < UFT.size(); ++i) {
      roots.insert(root(i));
    }
    return (LL)roots.size();
  }

  map<LL, vector<LL>> get_root_child() {
    map<LL, vector<LL>> a;
    for (LL i = 0; i < UFT.size(); ++i) {
      LL j = root(i);
      a[j].push_back(i);
    }
    return a;
  }

  void print() { 
    for (LL i = 0; i < UFT.size(); ++i) {
      cerr << root(i) << " ";
    }
    cerr << endl;
  }
};



#define cmax(a,b) {if(a<b){a=b;}}
#define cmin(a,b) {if(a>b){a=b;}}
#define EACH(a,A) for(auto a: A)
//#define cmax(a,b) a = (a>b ? a:b)
//#define cmin(a,b) a = (a<b ? a:b) 
//cin,cout高速化のおまじない＋桁数指定
inline VLL cinvll(LL N, LL minus = 0){
  VLL A(N);
  REP(i,N){
    cin >> A[i];
    A[i] -= minus;
  }
  return move(A);
}
inline VVLL zerosll(LL H, LL W, LL val=0){
  VVLL A(H,VLL(W,val));
  return move(A);
}
struct Fast{
	Fast(){
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast;


LL GCD(LL m, LL n) {

  if (m < n) {
    swap(m, n);
  }

  while (n != 0) {
    LL n_new = m % n;
    m = n;
    n = n_new;
  }

  return m;

}

VLL B;
VVLL T;
LL cnt=0;
void dfs(LL me,LL oya){

  for(LL i=0;i<T[me].size();i++){
    LL ko = T[me][i];
    if(ko==oya){
      continue;
    }
    cnt += min(B[me],B[ko]);
    dfs(ko,me);
  }

}
void func(){
  LL N;
  cin >> N;
  vector<string> S(N);
  REP(i,N){
    cin >> S[i];
  }
  LL cnt=0;
  
  vector<string> T = S;
  REP(k,N){
    REP(r,N){
      S[r] = T[(k+r)%N];
    }
    REP(r,N){
      //cout << S[r] << endl;
    }
    //cout << endl;
    
    bool flag = true;
    REP(i,N){
      REPM(j,N,i){
        //cerr << i << j << endl;
        if(S[i][j]!=S[j][i]){
          flag=false;
          break;
        }
      }
    }
    if(flag){
      cnt++;
    }
  }
  cout << cnt*N;
}


int main()
{
  func();
  return 0;
}
 