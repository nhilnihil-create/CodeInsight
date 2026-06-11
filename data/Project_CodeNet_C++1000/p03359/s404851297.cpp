#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,answer;
  cin >> a >> b;
  if(a<=b){
    answer=a;
  }
  else {
    answer=a-1;
  }
  cout << answer << endl;
}