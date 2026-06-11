#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  int n,kk;
  cin >> n >> kk;
  string s;
  cin >> s;
  int ans=0;
  int r=0,l=0;
  int k[n];
  rep(i,n)k[i]=0;
  rep(i,n-1){
    if(s[i]=='1'&&s[i+1]=='0')k[i]=1;
    else if(s[i]!=s[i+1])k[i]=-1;
  }
  int cnt=0;
  if(s[0]=='0')cnt++;
  rep(i,n){
    while(r<n-1){
      if(cnt==kk&&k[r]==1)break;
      if(k[r]==1)cnt++;
      r++;
    }
    ans=max(ans,r-l+1);
    if(k[l]==-1)cnt--;
    l++;
  }
  cout << ans << endl;
}
