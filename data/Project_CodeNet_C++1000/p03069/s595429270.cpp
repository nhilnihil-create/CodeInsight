#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  
  int ans1 = 0; //黒の個数
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '#') ans1++;
  }
  
  int ans2 = n - ans1; //白の個数
  
  int ans3 = n;
  int rb = 0; //左にある黒の数
  int rw = ans2; //右にある白の数
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '#'){rb++;}
    else{
      rw--;
      if(rb + rw < ans3){ans3 = rb + rw;}
    }
  }
  cout << min({ans1, ans2, ans3}) << endl;
  
}