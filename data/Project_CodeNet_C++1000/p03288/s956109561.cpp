#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
  
int main() {
  int n;
  cin >> n;
  if(n < 1200){
    cout << "ABC";
  }
  else if(n < 2800){
    cout << "ARC";
  }
  else{
    cout << "AGC";
  }
 
  return 0;
}

