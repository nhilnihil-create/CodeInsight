#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,num,sum = 0;
  cin >> a >> b;

  for(int i = a; i <= b; ++i){
    int r = 0;
    num = i;
    for(int j = 0; j < 5; ++j){
      r = r*10 + num%10;
      num /= 10;
    }
    if(i==r) ++sum;
  }
  cout << sum << endl;
}