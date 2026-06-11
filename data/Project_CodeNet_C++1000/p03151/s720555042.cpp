#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
#include<algorithm>
#include<numeric>
#include<limits>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
#define BEGIN ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define END return EXIT_SUCCESS
#define up(I,A,B) for(auto I=(A);I<=(B);++I)
#define dw(I,A,B) for(auto I=(A);I>=(B);--I)
#define rep(I,N) up(I,0,N-1)
#define all(C) (C).begin(),(C).end()
#define rall(C) (C).rbegin(),(C).rend()
#define ft first
#define sd second
#define mp make_pair
#define mt make_tuple
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rs resize
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>inline void                                      in(T &p){cin>>p;}
template<class T1,class T2>inline void                            in(T1 &p1,T2 &p2){cin>>p1>>p2;}
template<class T1,class T2,class T3>inline void                   in(T1 &p1,T2 &p2,T3 &p3){cin>>p1>>p2>>p3;}
template<class T1,class T2,class T3,class T4>inline void          in(T1 &p1,T2 &p2,T3 &p3,T4 &p4){cin>>p1>>p2>>p3>>p4;}
template<class T1,class T2,class T3,class T4,class T5>inline void in(T1 &p1,T2 &p2,T3 &p3,T4 &p4,T5 &p5){cin>>p1>>p2>>p3>>p4>>p5;}
template<class T>inline void                                      ins(T &p){for_each(all(p),in<decltype(p[0])>);}
template<class T>inline void                             out(T p){cout<<p<<endl;}
template<class T1,class T2>inline void                   out(T1 p1,T2 p2){cout<<p1<<" "<<p2<<endl;}
template<class T1,class T2,class T3>inline void          out(T1 p1,T2 p2,T3 p3){cout<<p1<<" "<<p2<<" "<<p3<<endl;}
template<class T1,class T2,class T3,class T4>inline void out(T1 p1,T2 p2,T3 p3,T4 p4){cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;}
inline                                              void out(ld p){printf("%.12Lf\n",p);}
template<class T>inline                             void outml(T p){for_each(all(p),out<decltype(p[0])>);}
template<class T>inline void outol(T V){int n=V.size();rep(i,n)cout<<V[i]<<" \n"[i==n-1];}
inline void solve(void){
  int N;
  in(N);
  vector<int>A(N),B(N);
  ins(A);ins(B);
  priority_queue<int>q;
  long lack=0;
  long cnt=0;
  long sum=0;
  rep(i,N)sum+=A[i]-B[i];
  if(sum<0){
    out(-1);
    return;
  }
  rep(i,N){
    if(A[i]>B[i])q.push(A[i]-B[i]);
    if(A[i]<B[i])lack+=B[i]-A[i],cnt++;
  }
  while(!q.empty()){
    int e=q.top();q.pop();
    if(lack<=0)break;
    lack-=e;
    cnt++;
  }
  if(lack<=0)out(cnt);
}
int main(int argc,char**argv){
  BEGIN;
  solve();
  END;
}
