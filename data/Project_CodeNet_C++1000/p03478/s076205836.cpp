#include<iostream>
using namespace std;
int digit(int n){
  int ans=0;
  while(n!=0){
	ans+=n%10;
    n=n/10;
   }
  return ans;
}
int main(){
  int n,a,b,i;
  cin >> n >> a >> b;
  int ans=0;
  for(i=1;i<=n;i++){
    if(digit(i)>=a && digit(i)<=b){
      ans+=i;
    }
  }
  cout << ans << endl;
  return 0;
}
