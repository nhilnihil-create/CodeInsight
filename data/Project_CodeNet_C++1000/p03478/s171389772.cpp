#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int ans=0;
  for(int i=1;i<=n;i++){
    int sum=0;
    sum+=i/10000;
    sum+=(i-i/10000*10000)/1000;
    sum+=(i-i/1000*1000)/100;
    sum+=(i-i/100*100)/10;
    sum+=i-i/10*10;
    if(a<=sum && b>=sum) ans += i;
  }
  
  cout << ans << endl;
  return 0;
}
