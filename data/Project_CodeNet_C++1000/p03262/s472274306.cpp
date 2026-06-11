#include<bits/stdc++.h>
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
    int n,x;
    cin >> n >> x;
    int a;
    int b[n];
    for(int i=0;i<n;i++){
        cin >> a;
        b[i]=abs(a-x);
    }

    if(n>1){
    int ans=gcd(b[0],b[1]);
    for(int i=2;i<n;i++)ans=gcd(ans,b[i]);
    cout << ans << endl;
    }
    else cout << b[0] << endl;
}