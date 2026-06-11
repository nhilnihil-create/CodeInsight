#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 99999999;
  bool black = false;
  bool tmp = false;
  int i;
  vector<int>b(n);
  vector<int>w(n);
  for(i=0;i<n;i++){
    if(s[i]=='#')b[i]++;
    else w[i]++;
  }
  for(i=1;i<n;i++){
    b[i]=b[i-1]+b[i];
    w[i]=w[i-1]+w[i];
  }
  if(s[0]=='#')black = true;
  else black = false;
  for(i=0;i<n;i++){
    if(ans>b[i]+w[n-1]-w[i])ans = b[i]+w[n-1]-w[i];
  }
  if(w[n-1]<ans)ans = w[n-1];
  if(b[n-1]<ans)ans = b[n-1];


  cout << ans << endl;
}
