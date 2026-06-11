#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int count = 0;
  for (int i = a;i <= b;i++){
    if( (i / 10000) == (i % 10) ){
      int tmp = i;
      tmp %= 10000;
      if(tmp < 10){
        count++;
        continue;
      }
      if(tmp < 100){
        continue;
      }
      tmp /= 10;
      //cout << tmp << endl;
      if( (tmp / 100) == (tmp % 10) ){
        count++;
      }
    }
  }
  cout << count << endl;
}
