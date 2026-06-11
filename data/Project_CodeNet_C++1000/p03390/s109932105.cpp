#include <iostream>
#include<math.h>
typedef long long ll;
using namespace std;
int main(){
  int n;cin>>n;
  while(n--){
    ll a,b;
    cin>>a>>b;
    ll ret=sqrt(a*b);
    cout<<(a*b-(a!=b))/ret+ret-2<<endl;
    }
  return 0;
  }