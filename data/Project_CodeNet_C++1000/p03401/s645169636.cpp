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
  ll all=0;
  rep(i,n){ cin>>a[i]; }
  rep(i,n-1){
    all += abs(a[i]-a[i+1]);
  }
  all += abs(a[0])+abs(a[n-1]);
  
  cout << all-abs(a[0])-abs(a[0]-a[1])+abs(0-a[1]) << endl;
  for(int i=1; i<n-1; i++){
    int ans = all-abs(a[i]-a[i+1])-abs(a[i-1]-a[i])+abs(a[i-1]-a[i+1]);
    cout << ans << endl;
  }
  cout << all-abs(a[n-1])-abs(a[n-1]-a[n-2])+abs(0-a[n-2]) << endl;
  
  return 0;
}