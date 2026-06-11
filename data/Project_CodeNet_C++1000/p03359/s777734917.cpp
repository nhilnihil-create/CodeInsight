#include<bits/stdc++.h>
using namespace std;

int main(){
 
  int a, b;
  cin >> a >> b;
  int cnt = a - 1;
  if(b >= a) cnt++;
  cout << cnt << endl;
  return 0;
}


