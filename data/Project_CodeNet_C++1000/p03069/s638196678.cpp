#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,wh[200005]={};
  string s;
  
  cin >> n >> s;
  
  for (i=0;i<n;i++){
    if (s[i]=='.') wh[i+1]=wh[i]+1;
    else wh[i+1]=wh[i];
  }
  
  int syg,ans=1e9;
  for (i=0;i<=n;i++){
    syg=i-wh[i]+wh[n]-wh[i];
    ans=min(ans,syg);
  }
  
  cout << ans << endl;
  
  return 0;
}