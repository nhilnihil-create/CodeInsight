#include <bits/stdc++.h>
#define r(x,i,n) for(int i = x; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  ll a,b;
  int k,n=0;
  cin >> a >> b >> k;
  while(k--){
    if(n%2==0){
      if(a%2==1){
        b+=a/2;
        a=a-a/2-1;
      }
      else{
        b+=a/2;
        a/=2;
      }
    }
    else{
      if(b%2==1){
        a+=b/2;
        b=b-b/2-1;
      }
      else{
        a+=b/2;
        b/=2;
      }
    }
    n++;
  }
  cout << a <<" " << b << endl;
}
