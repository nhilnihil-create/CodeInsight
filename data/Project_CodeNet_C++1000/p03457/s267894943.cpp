#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int ans=1;
  int t=0,x=0,y=0;
  
  for(int i=0;i<n;i++){
    int a,b,c;
    cin >> a >> b >> c;
    int p=max(b-x,x-b)+max(c-y,y-c);
    ans*=(a-t>=p&&(a-t-p)%2==0);
    if(ans==0) break;
    t=a;
    x=b;
    y=c;
  }
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}