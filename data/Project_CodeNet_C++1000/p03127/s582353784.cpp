#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return (b!=0 ? gcd(b,a%b) : a);}
int main(void){
  ll i,n,a,result=0;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a;
    if(i==0) result=a;
    else result = gcd(result,a);
  }
  cout << result << endl;
  return 0;
}