#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b;
  cin >> N;
  a = N % 10;
  b = N / 1000;
  if(((N - a)% 111 == 0) || ((N - b*1000)%111 == 0)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }  
}