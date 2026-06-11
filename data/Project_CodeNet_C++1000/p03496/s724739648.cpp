#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int maxi=-inf;
  int xi=-1;
  int mini=inf;
  int ni=-1;
  rep(i,n){
    cin >> a[i];
    if(a[i]>maxi){maxi = a[i]; xi=i; }
    if(a[i]<mini){mini = a[i]; ni=i; }
  }
  
  vector<P> ans;
  if(abs(maxi)>=abs(mini)){
    rep(i,n)if(a[i]<0){
      ans.emplace_back(xi+1,i+1);
    }
    for(int i=0; i<n-1; i++){
      ans.emplace_back(i+1,i+2);
    }
  } else {
    rep(i,n)if(a[i]>0){
      ans.emplace_back(ni+1,i+1);
    }
    for(int i=n-1; i>0; i--){
      ans.emplace_back(i+1,i);
    }
  }
  
  cout << ans.size() << endl;
  rep(i,ans.size()){
    cout<<ans[i].F<<" "<<ans[i].S<<" "<<endl;
  }
  return 0;
}