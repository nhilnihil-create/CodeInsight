#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=0, sum=0;
  cin >> n;
  vector<int>t(n+1,0),x(n+1,0),y(n+1,0);
  for(int i=1;i<=n;i++){
    cin >> t[i] >> x[i] >> y[i];
  }
  for(int i=1;i<=n;i++){
    sum=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
    if(sum>(t[i]-t[i-1])){
      cout << "No" << endl;
      return 0;
    }
    if(sum%2 != (t[i]-t[i-1])%2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}