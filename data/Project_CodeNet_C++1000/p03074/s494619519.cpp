#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n,k,count=0;
  string s;
  vector<int>si,so;
  cin >> n >> k>>s;
  char c=s[0];
  if(c=='0')
    si.push_back(0);
  rep(i,n){
    if (c==s[i]) {
      count++;
    } else {
      if (c == '0')
        so.push_back(count);
      else
        si.push_back(count);
      count=1;
      c=s[i];
    }
  }
  if (c == '0'){
    so.push_back(count);
    si.push_back(0);
  }else
    si.push_back(count);
  int ss=so.size();
  if(ss<=k){
     cout<<n; 
  }else{
    int sum=0;
    rep(i,k)
      sum+=si[i]+so[i];
    sum+=si[k];
    int ans=sum;
    for(int i=k;i<ss;i++){
       sum+=si[i+1]+so[i]-(si[i-k]+so[i-k]);
       ans=max(ans,sum); 
    }
    cout<<ans;
  }
  return 0;
}
