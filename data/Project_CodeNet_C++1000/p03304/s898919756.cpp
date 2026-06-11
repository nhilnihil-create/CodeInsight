#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int main(){
  double a,b,c,d;cin>>a>>b>>c;
  if(c==0.0)d=(b-1.0)/a;
  else d=2.0*(b-1.0)*(a-c)/(a*a);
  cout<<fixed<<setprecision(18)<<d;
}