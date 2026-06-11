#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include <random>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n;
  cin >> n;
  ll a[n];
  bool used[n]={};
  rep(i,n){
    cin >> a[i];
  }
  sort(a,a+n);
  ll ans=0;
  ll x[31]={};
  x[0]=1;
  rep(i,30)x[i+1]=2*x[i];
  for(int i=30;i>=0;i--){
    int left=0,right=n-1;
    while(left<right){
      if(used[left]){
        left++;
        continue;
      }
      if(used[right]){
        right--;
        continue;
      }
      if(a[left]+a[right]==x[i]){
        used[left]=true;
        used[right]=true;
        left++;
        right--;
        ans++;
      }
       if(a[left]+a[right]<x[i]){
         left++;
       }
       if(a[left]+a[right]>x[i]){
         right--;
       }
    }
  }
  cout << ans << endl;
return 0;}