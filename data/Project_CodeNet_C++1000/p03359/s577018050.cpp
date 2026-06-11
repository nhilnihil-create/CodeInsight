#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  
  int count = 0;
  count += (a- 1);
  if(a <= b) count++;
  
  cout << count << endl;
}
