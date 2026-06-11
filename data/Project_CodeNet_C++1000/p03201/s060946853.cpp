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
  lint N,ans=0;
  cin >> N;
  multiset<lint> A;
  lint pow2[40];
  pow2[0]=1;
  rep(i,39) pow2[i+1]=pow2[i]*2;
  rep(i,N){
    lint X;
    cin >> X;
    A.insert(X);
  }
  while(A.size()>1){
    bool check=false;
    auto itr=A.end();
    itr--;
    rep(i,33){
      if(A.count(pow2[i]-*itr)){
        auto itr2=A.find(pow2[i]-*itr);
        if(itr==itr2 && A.count(pow2[i]-*itr)==1) continue;
        else if(itr==itr2) itr2++;
        ans++;
        A.erase(itr);
        A.erase(itr2);
        check=true;
        break;
      }
    }
    if(!check) A.erase(*itr);
  }
  cout << ans << endl;
}