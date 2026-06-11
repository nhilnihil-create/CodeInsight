#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin>>s>>k;
  int n=s.size();
  int one=0;
  char ans;
  for(int i=0;i<n;i++){
    if(s[i]=='1') one++;
    else{
      ans=s[i];
      break;
    }
  }
  if(one>=k) cout<<1<<endl;
  else cout<<ans<<endl;
}
