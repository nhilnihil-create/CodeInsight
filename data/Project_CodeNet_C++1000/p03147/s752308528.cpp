#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m=0,b,ans=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> b;
    ans+=max(b-m,0);
    m=b;
  }
  cout << ans << endl;
  return 0;
}