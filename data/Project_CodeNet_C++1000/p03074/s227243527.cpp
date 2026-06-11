#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  
  vector<int> a;
  int res = 1;
  s[n] = (s[n-1]+1)%2;
  if(s[0]=='0') a.pb(0);
  rep(i,n){
    if(s[i]==s[i+1]){
      res++;
    }else{
      a.pb(res);
      res = 1;
    }
  }
   
  int ans = 0;
  int res2 = 0;
  int p = a.size()-2*k+1;

  rep(i,max(p,1)){
    rep(j,2*k){
      if(i+j<a.size()) res2 += a[i+j];
    }
    if(i%2==0&&i+2*k<a.size()) res2 += a[i+2*k];
    ans = max(ans,res2);
    res2 = 0;
  }
  cout << ans << endl;
}