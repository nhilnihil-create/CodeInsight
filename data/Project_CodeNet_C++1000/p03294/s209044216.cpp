#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  long long cnt = 0;
  long long kekka = 0;
  
  cin >> num;
  
  for(long long i = 0; i < num; i++){
    cin >> cnt;
    kekka += cnt-1;
  }
  
  cout << kekka;
}
