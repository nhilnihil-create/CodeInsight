#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  long a,b,c,d;
  string abcd;
  cin >> abcd;
  a=abcd[0]-'0';
  b=abcd[1]-'0';
  c=abcd[2]-'0';
  d=abcd[3]-'0';
  
  vector<int> p(3); 
  p[0] = b;
  p[1] = c;
  p[2] = d;
  
  for(ll bit = 0; bit < (1<<3); ++bit){
    int sum;
    sum = a;
    
    for(int i = 0; i < 3; i++){
    if(bit & (1<<i)){
      sum = sum + p[i];
    }
    else{
      sum = sum - p[i];
    }
    }
    
    if(sum == 7){
      string x, y, z;
      if(bit & (1<<0)){
      x = '+';
      }
      else{
      x = '-';
      }
      if(bit & (1<<1)){
      y = '+';
      }
      else{
      y = '-';
      }
      if(bit & (1<<2)){
      z = '+';
      }
      else{
      z = '-';
      }
      cout << a << x << p[0] << y << p[1] << z << p[2] << '=' << 7;
      return 0;
    }
  }
  return 0;
}