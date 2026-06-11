#include<bits/stdc++.h>
using namespace std;

int main(){
  int a[1000000] = {};
  int s;
  cin >> s;
  a[s - 1]++;
  int count = 1;
  while(true){
    count++;
    if(s % 2 == 0) s /= 2;
    else s = 3 * s + 1;
    if(a[s - 1] > 0){
      cout << count << endl;
      return 0;
    }else a[s - 1]++;
  }
}