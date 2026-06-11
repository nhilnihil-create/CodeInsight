#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
  int n;
  string s;
  cin>>n>>s;
  
  vector<int> a(n+1),b(n+1);
  rep(i,n){
    if(s[i]=='.'){
      a[i+1]=a[i]+1;
      b[i+1]=b[i];
    }else{
      a[i+1]=a[i];
      b[i+1]=b[i]+1;
    }
  }
  int ans = n+1;
  rep(i,n+1){
    ans = min(ans,a[n]-a[i]+b[i]);
  }
  cout << ans << endl;
}

