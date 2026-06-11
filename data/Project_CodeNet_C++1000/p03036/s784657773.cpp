#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,d,f;
  cin >> r >> d >> f;
  long long p = r * f - d;
  cout << p << endl;
  for(int i = 1; i < 10; i++){
    p = r * p - d;
    cout << p << endl;
  }
}