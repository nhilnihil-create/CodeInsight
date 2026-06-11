#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  for(int i=0;i<n;i++){
    ans+=s[i]-'0';
  }
  cout<<max(ans,9*(n-1)+(s[0]-'0')-1)<<endl;
}
