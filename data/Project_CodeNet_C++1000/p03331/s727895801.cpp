#include<iostream>
using namespace std;
int main(){
  int a;cin >> a;
  if(a==10 || a==100 || a==1000 || a==10000 ||a==100000) cout << 10 << endl;
  else{
    int ans = 0;
    while(a){
      ans += a%10;a /= 10;
    }
    cout << ans << endl;
  }
}