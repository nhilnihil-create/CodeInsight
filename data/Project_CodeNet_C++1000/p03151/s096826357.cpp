#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    cin>>b[i];
  }
  int ans=0;
  vector<int> plus;
  ll minus=0;
  rep(i,n){
    if(a[i] < b[i]){
      ans++;
      minus+=b[i]-a[i];
    }
    if(a[i] > b[i]){
      plus.push_back(a[i]-b[i]);
    }
  }
  sort(plus.begin(),plus.end(),greater<int>());
  for(auto x : plus){
    if(minus<=0)break;
    minus-=x;
    ans++;
  }
  if(minus>0) cout<<-1<<endl;
  else cout<<ans<<endl;
}
