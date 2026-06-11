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
  int N;
  cin >> N;
  int A[N];
  rep(i,N) cin >> A[i];
  sort(A,A+N,greater<int>());
  int max=A[0];
  int mid1=ceil((double)max/2),mid2=max/2;
  int ans=INF;
  for(int i=1;i<N;i++){
    if(abs(ans-mid1)>abs(A[i]-mid1)) ans=A[i];
    if(abs(ans-mid2)>abs(A[i]-mid2)) ans=A[i];
  }
  cout << max << " " << ans << endl;
}