#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  if(a%b==0)
    return(b);
  else
    return(gcd(b,a%b));
}

int main(){
  int n,x;
  cin >> n >> x;
  vector<int> a(n+1,x);
  for(int i=0;i<n;i++) cin >> a[i];
  
  int ans=abs(a[0]-x);
  for(int i=1;i<n;i++) ans=gcd(ans,abs(a[i]-a[i-1]));
  
  cout << ans << endl;
}