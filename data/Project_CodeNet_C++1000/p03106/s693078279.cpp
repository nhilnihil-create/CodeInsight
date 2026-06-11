#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y){
 long long int tmp;
 long long int r;
 if(x > y){
    tmp = x;
    x = y;
    y = tmp;
  }
  r = y % x;
  while(r!=0){
    y = x;
    x = r;
    r = y % x;
  }
  return x;
}
int main(){
    long long int a,b,k;
    cin >> a >> b >> k;
    long long int ans;
    ans=gcd(a,b);
    int count=0;
    for(long long int i=ans;i>0;i--){
        if(ans%i==0)count++;
        if(count==k){
            ans=i;
            break;
        }
    }
    cout << ans << endl;
}