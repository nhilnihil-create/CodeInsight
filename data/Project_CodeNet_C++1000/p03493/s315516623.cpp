#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,cnt = 0;
  cin >> a;
  cnt += a/100;
  cnt += (a/10) % 2;
  cnt += a%2;
  cout << cnt << endl;
}
 
