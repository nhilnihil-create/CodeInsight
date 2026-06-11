#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin>>n;
  vector<int> b(n);
  rep(i,n){
    cin>>b[i];
    b[i]--;
  }
  
  vector<int> ans;
  rep(k,n){
    for(int i=n-1;i>=0;i--){
      if(b[i]==i){
        ans.pb(b[i]+1);
        for(int j=i;j<=n-2;j++) b[j]=b[j+1];
        b[n-1]=-1;
        break;
      }
    }
  }
  
  if(int(ans.size())!=n) puts("-1");
  else{
    rep(i,n) cout << ans[n-i-1] << endl;
  }
}



