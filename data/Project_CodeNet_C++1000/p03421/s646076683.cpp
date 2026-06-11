#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);


  // a + b - 1 <= n

  ll n,a,b;
  cin >> n >> a >> b;
  if(a+b-1>n || a*b < n){
    cout << -1 << endl;
    return 0;    
  }

  vector<int> ans;
  for(int i=b;i>=1;i--) ans.pb(i);
  int need = a-1;
  for(int i=b+1;i<=n;i++){
    deque<int> tans;
    tans.push_back(i);
    need--;
    int c=1;
    while(c<b && need < (n-i) && i<n){
      c++;i++;
      tans.push_front(i);
      //      cout << i << endl;
    }
    rep(j,tans.size()) ans.pb(tans[j]);
  }
  rep(i,n) cout << ans[i] << " \n"[i==n-1];
  
  return 0;
    

}
