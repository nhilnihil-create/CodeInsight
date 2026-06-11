#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr8,pr7,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
#define prArr(a) {cerr<<(#a)<<"={";int i=0;for(auto t:(a))cerr<<(i++?", ":"")<<t;cerr<<"}"<<endl;}
using namespace std;
using Int = long long;
using _int = int;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<60)+1e9; // ~ 1.15 * 1e18
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
template<class T1, class T2> ostream& operator<<(ostream& o,pair<T1,T2> p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T1, class T2, class T3> ostream& operator<<(ostream& o,tuple<T1,T2,T3> t){
  return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class T1, class T2> istream& operator>>(istream& i,pair<T1,T2> &p){return i>>p.first>>p.second;}
template<class T> ostream& operator<<(ostream& o,vector<T> a){Int i=0;for(T t:a)o<<(i++?" ":"")<<t;return o;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(T &t:a)i>>t;return i;}
//INSERT ABOVE HERE

set<P> S;
vector<vector<Int> > X;
Int H, W, N;

Int calc(Int x,Int y){
  Int idx = lower_bound(X[y].begin(), X[y].end(), x) - X[y].begin();
  return X[y][idx] - x;
}

Int bfs(){
  using T = tuple<Int,Int,Int>;
  queue<T> Q;
  map<T,Int> D;
  vector<Int> used(H+1);
  map<T,Int> visited;
  Q.push(T(0, 0, 0));
  D[T(0, 0, 0)] = 0;

  Int ans = INF;
  while(!Q.empty()){
    Int x, y, turn;
    tie(x, y, turn) = Q.front(); Q.pop();
    Int cost = D[T(x, y, turn)];
    if(!used[y]) Min(ans, cost + calc(x, y));
    visited[T(x, y, turn)] = 1;
    used[y] = 1;
    
    if(turn == 0 && used[y+1] == 0){
      if(S.count(P(x+1, y)) || x+1 >= W) continue;
      Q.push(T(x+1, y, !turn));
      D[T(x+1, y, !turn)] = cost;
    }
    if(turn == 1){
      if(S.count(P(x, y+1))){
	if(!visited[T(x, y, !turn)]){
	  Q.push(T(x, y, !turn));
	  D[T(x, y, !turn)] = cost+1;
	}
      }
      else if(y+1 < H){
	Q.push(T(x, y+1, !turn));
	D[T(x, y+1, !turn)] = cost + 1;
      }
    }
  }
  return ans;
}
signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);


  cin>>W>>H>>N;
  X.resize(H);
  for(Int i=0;i<N;i++){
    Int x, y;
    cin>>x>>y; x--, y--;
    S.insert(P(x, y));
    X[y].push_back(x);
  }
  for(Int i=0;i<H;i++) {
    X[i].push_back(W);
    sort(X[i].begin(),X[i].end());
  }

  Int ans = bfs();
  cout<<ans<<endl;

  
  return 0;
}
