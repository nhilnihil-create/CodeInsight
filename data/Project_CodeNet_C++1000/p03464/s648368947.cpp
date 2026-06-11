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
  int K;
  cin >> K;
  lint A[K];
  reprev(i,K) cin >> A[i];
  lint maxi=2,mini=2;
  bool check=true;
  rep(i,K){
    if(maxi<A[i]) check=false;
    if(maxi/A[i]==mini/A[i] && mini%A[i]!=0 && maxi%A[i]!=0) check=false;
    lint rem=maxi/A[i],rem2=ceil((double)mini/A[i]);
    maxi=rem*A[i]+A[i]-1;
    mini=rem2*A[i];
   }
   if(check) cout << mini << " " << maxi << endl;
   else cout << -1 << endl;
}