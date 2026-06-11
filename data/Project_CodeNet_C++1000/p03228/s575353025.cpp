#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll a,b,k;
  cin >> a >> b >> k;
  bool ao,ta;
  ta=true;
  ao=false;
  while(k>0){
    k--;
    if(ta){
      ta=false;
      ao=true;
      if(a%2!=0 && a>0) a--;
      b+=(a/2);
      a=a/2;
    }else{
      ao=false;
      ta=true;
      if(b%2!=0 && b>0) b--;

      a+=(b/2);
      b=b/2;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}
