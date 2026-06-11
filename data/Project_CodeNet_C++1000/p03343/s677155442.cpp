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

  int n,k,q;
  cin >> n >> k >> q;
  int a[n];
  rep(i,n){
    cin >> a[i];
  }
  int ans=INT_MAX;
  rep(i,n){
    vector<int> ans_can;
    int x=a[i];
    vector<int> t;
    rep(j,n){
      if(j==i && j!=n-1){
	t.pb(a[j]);
      }
      else if(a[j]>=a[i] && j!=n-1) t.pb(a[j]);
      else{
	if(j==n-1 && a[j]>=a[i]) t.pb(a[j]);
	sort(t.begin(),t.end());
	rep(l,t.size()){
	  if(t.size()-1-l+1<k) break;
	  ans_can.pb(t[l]);
	}
	t.clear();
      }
    }
    if(!ans_can.empty()){
      sort(ans_can.begin(),ans_can.end());
      //      rep(i,ans_can.size()) cout << ans_can[i] << endl;
      if(ans_can.size()>=q) ans=min(ans_can[q-1]-x,ans);
    }
    //cout << ans << endl;
  }
  cout << ans << endl;


  
  return 0;
    

}
