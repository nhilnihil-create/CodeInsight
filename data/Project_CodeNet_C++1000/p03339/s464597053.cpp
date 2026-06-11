#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ans(n,0);
  int w=0,e=0;
  for(int i=n-1;i>=0;i--){
    ans[i]+=e;
    if(s[i]=='E')e++;
  }
  for(int i=0;i<n;i++){
    ans[i]+=w;
    if(s[i]=='W') w++;
  }
  int fans=n;
  for(int i=0;i<n;i++){
    fans=min(fans,ans[i]);
  }
  cout << fans << endl;
}
