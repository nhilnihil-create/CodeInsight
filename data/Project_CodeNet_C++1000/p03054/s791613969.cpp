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


int check(string S, string T, int X, int W){
  int N = S.size();
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());
  T[0] = '.';
  //pr(S, T, X, W);
  
  int l = 1, r = W;
  for(int i=0;i<N;i++){

    //落とされたくない
    if(T[i] == 'R') l--; 
    if(T[i] == 'L') r++;

    Max(l, 1);Max(r, 1);Min(l, W);Min(r, W);
    
    //落としたい
    if(S[i] == 'R') r--;
    if(S[i] == 'L') l++;
    
    //pr(i, l, r, X, W, S[i], T[i]);
    if(r < 1 || l > W || l > r) return 0;
  }
  return (l <= X && X <= r);
}

signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int H, W, N;
  cin>>H>>W>>N;
  int sy, sx;
  cin>>sy>>sx;

  string S, T;
  cin>>S>>T;

  string Sx, Sy, Tx, Ty;

  for(int i=0;i<N;i++){
    if(S[i] == 'L' || S[i] == 'R') Sx += S[i], Sy += '.';
    else Sy += S[i] == 'U'? 'L':'R', Sx += '.';
    
    if(T[i] == 'L' || T[i] == 'R') Tx += T[i], Ty += '.';
    else Ty += T[i] == 'U'? 'L':'R', Tx += '.';
  }
  
  int a = check(Sy, Ty, sy, H);
  int b = check(Sx, Tx, sx, W);
  int ans = a & b;
  //pr(a, b);
  cout<<(ans? "YES":"NO")<<endl;
  
  return 0;
}
