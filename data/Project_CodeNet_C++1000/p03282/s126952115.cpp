#include <bits/stdc++.h>
using namespace std;

int main() {
  string num;
  long long k;
  string kekka = "";
  cin >> num >> k;
  
  for(long long i = 0; i < min(k,(long long)num.size()); i++){
    if(num.at(i) == '1'){
      continue;
    }else{
      kekka = num.at(i);
      break;
    }
  }
  
  if(kekka == "") kekka = '1';
  
  cout << kekka; 
}
