#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b;
  int k;
  cin >> a >> b >> k;
  for(int i=0;i<k;i++){
    if(i%2==0){
      if(a%2) a--;
      a/=2;
      b+=a;
    }
    else{
      if(b%2) b--;
      b/=2;
      a+=b;
    }
  }
  cout << a << " " << b << endl;
}