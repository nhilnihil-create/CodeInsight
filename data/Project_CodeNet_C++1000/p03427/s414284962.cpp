#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
 
using namespace std;
using P = pair<int,int>;
 
 
unsigned GetDigit(long long num){
    unsigned digit = 0;
    while(num != 0){
        num /= 10;
        digit++;
    }
    return digit;
}
 
int main(){
 
  ll N;
  cin >> N;
  ll ans = 0;
  int digit;
 
  digit = GetDigit(N);
 
  if(digit == 1){
    cout << N << endl;
    return 0;
  }
 
  // 199のような場合を求める
  string num = to_string(N);
  bool flag = false;
  for (int i = 1; i < num.size(); i++) {
    if(num[i] == '9'){
      flag = true;
    }else{
      flag = false;
      break;
    }
  }
 
  if(flag == true){ // 199のような9で詰まる場合は全て足す
    for (int i = 0; i < num.size(); i++) {
      int ni = (int)(num[i]-'0');
      ans += ni;
    }
  }else{ // そうじゃない場合は先頭の桁を切り下げた数値と以下9を足す
    for (int i = 0; i < num.size(); i++) {
      int ni;
      if(i == 0){
        ni = (int)(num[i]-'0') -1;
      } else {
        ni = 9;
      }
      ans += ni;
    }
  }
 
  cout << ans << endl;
 
  return 0;
}