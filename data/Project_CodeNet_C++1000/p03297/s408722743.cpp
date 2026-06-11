#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
const int INF=1e+9;
const ll INFLL=1e+17;
int T;
ll A[310],B[310],C[310],D[310];
ll gcd(ll a,ll b){
  if(b==0) return a;
  else return gcd(b,a%b);
}
void solve(int i){
  ll a=A[i],b=B[i],c=C[i],d=D[i];
  if(a<b){
    prin("No");return ;
  }
  if(d<b){
    prin("No");return ;
  }
  a%=b;
  ll g=gcd(b,d);
  //  prin(g);
  if((b-a)%g==0){
    if(b-g>c){
      prin("No");return ;
    }
    else{
      prin("Yes");return ;
    }
  }
  else{
    ll x=(b-a)/g*g+a;
    if(x>c){
      prin("No");return ;
    }
    else{
      prin("Yes");return ;
    }
  }
}
int main(){
  cin>>T;
  rep(i,T) cin>>A[i]>>B[i]>>C[i]>>D[i];
  rep(i,T){
    solve(i);
  }
  return 0;
}
