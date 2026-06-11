#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<long long> s(n+1,0);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    s[i+1]=s[i]+a;
  }
  sort(s.begin(),s.end());
  
  long long ans=0,cnt=0;
  for(int i=0;i<n;i++){
    if(s[i]==s[i+1]) {cnt++;ans+=cnt;}
    else cnt=0;
  }
  cout<<ans<<endl;
}