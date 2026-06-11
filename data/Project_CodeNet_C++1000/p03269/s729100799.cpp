#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>//pair
#include<cmath>//abs,sqrt
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int INF=1e+9;
const ll INFLL=1e+17;
int l;
int b[30];
void make_bit(){
  int a=1;
  rep(i,25){
    b[i]=a;
    a*=2;
  }
}
int bit_search(int x){
  if(x==0) return 0;
  int i=0;
  while(b[i]<=x) i++;
  return i-1;
}
void solve(){
  make_bit();
  int n=bit_search(l);
  int N=n+1,M=2*n;
  int res[70][5];
  int k=0;
  rep1(i,N-1){
    res[k][0]=i;
    res[k][1]=i+1;
    res[k][2]=0;
    res[k+1][0]=i;
    res[k+1][1]=i+1;
    res[k+1][2]=b[i-1];
    k+=2;
  }
  int mx=b[n];
  while(l>mx){
    int nn=bit_search(l-mx);
    res[k][0]=nn+1;
    res[k][1]=N;
    res[k][2]=mx;
    k++;
    mx+=b[nn];
    M++;
  }
  prin2(N,M);
  rep(i,M){
    rep(j,3){
      cout<<res[i][j]<<" ";
    }
    cout<<"\n";
  }
}
int main(){
  cin>>l; 
  solve();
  return 0;
}
