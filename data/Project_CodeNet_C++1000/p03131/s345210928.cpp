#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  ll k,a,b,ans;
  
  cin >> k >> a >> b;
  
  if (b-a>=2 && k>=a+1){
    ans=a+(b-a)*((k-a+1)/2)+(k-a+1)%2;
  }else{
    ans=k+1;
  }
  
  cout << ans << endl;
  
  return 0;
}