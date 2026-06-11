#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
 
int main() {
  int n;
  string s;
  cin>>n>>s;
  int b=0,w=0;
  rep(i,n){
    if(s[i]=='#') b++;
    else w++;
  }
  int ans=w;
  int lb=0,rw=w;
  rep(i,n){
    if(s[i]=='#'){
      lb++;
    }
    else{
      rw--;
    }
    ans=min(ans,lb+rw);
  }
  cout<<ans<<endl;
}