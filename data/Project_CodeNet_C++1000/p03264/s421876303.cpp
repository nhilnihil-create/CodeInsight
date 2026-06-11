#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  int kisu,gusu;
  int kekka;
  
  cin >> k;
  
  if(k % 2 == 0){
    kisu = k / 2;
    gusu = k / 2;
  }else{
    kisu = k / 2 +1;
    gusu = k / 2;
  }
  
  kekka = kisu * gusu;
  cout << kekka;
}
