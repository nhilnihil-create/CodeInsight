#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, s, n;
  string num;
  cin >> N;
  s = 0;
  n = N;
  for(int i = 0; i < 9 ; i++){
    int a;
    a = n / pow(10,(8-i));
    s += a;
    n -= a * pow(10,(8-i));
    //cout << a << ":" << s << ":" << n << endl;
  }
  if(N % s == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}

  