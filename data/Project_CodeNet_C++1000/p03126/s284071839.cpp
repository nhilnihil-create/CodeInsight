#include <bits/stdc++.h>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))
 
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,m;
  cin>>n>>m;
  
  vector<int> num(m);
  
  rep(i,n) {
    int k;
    cin>>k;
    
    rep(i,k) {
      int a;
      cin>>a;
      
      num[a-1]+=1;
    }
  }

  int ans = 0;
  rep(i,m) {
    if(num[i]==n) {
      ++ans;
    }
  }
  
  cout<<ans;
    
  return 0;
}