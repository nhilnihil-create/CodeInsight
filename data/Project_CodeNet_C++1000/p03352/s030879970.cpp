#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int x;
  cin >> x;
  
  int num=0,max=0;
  for(int b=1; b<=1000; b++){
	for(int p=2; p<=1000; p++){
      num = pow(b,p);
      if(num<=x && max<num) max = num;
    }
    if(num>=x) break;
  }
  cout << max << endl;
}