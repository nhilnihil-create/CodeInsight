#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
  lint K;
  cin >> K;
  lint A[K];
  reprev(i,K) cin >> A[i];
  lint CMAX=2,CMIN=2;
  bool check=true;
  rep(i,K){
    if(CMIN%A[i]<=CMAX%A[i] && CMIN/A[i]==CMAX/A[i] && CMIN%A[i]!=0 && CMAX%A[i]!=0) check=false;
    if(CMAX>=A[i]){
      CMIN=((CMIN+A[i]-1)/A[i])*A[i];
      CMAX=(CMAX/A[i])*A[i]+A[i]-1;
    }
    else check=false;    
  }
  if(check) cout << CMIN << " " << CMAX << endl;
  else cout << -1 << endl;
}