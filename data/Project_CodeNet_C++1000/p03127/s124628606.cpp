#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  if(a%b==0)
    return(b);
  else
    return(gcd(b,a%b));
}

int main(){
  int n;
  cin >> n;
  int ans;
  cin >> ans;
  for(int i=1;i<n;i++){
    int a;
    cin >> a;
    ans=gcd(ans,a);
  }
  cout << ans << endl;
}