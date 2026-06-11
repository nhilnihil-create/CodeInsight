#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a, b, k;
  cin >> a >> b >> k;
  for(int i = 0; i < k; i++){
    if(i % 2 == 0){
      if(a % 2 == 1) a--;
      b += a / 2;
      a -= a / 2;
    }else{
      if(b % 2 == 1) b--;
      a += b / 2;
      b -= b / 2;
    }
  }
  cout << a << " " << b << endl;
}