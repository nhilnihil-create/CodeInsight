//先頭の数字が9以外の場合、一つ下げて残りを９
#include <bits/stdc++.h>
using namespace std;

int main(){
long long n;
  cin >> n;
  int count =0;
  bool ans = true; 
  while(n>=10){
    if(n%10!=9){
      ans = false;
    }
    n /= 10;
    count++;
  }
  
  if(ans) cout << 9*(count)+n << endl;
  else cout << 9*(count)+n-1 << endl;
}
  