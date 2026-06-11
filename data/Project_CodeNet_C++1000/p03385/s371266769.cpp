#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  string x;
  cin >> x;
  if(x[0] != x[1] && x[1] != x[2] && x[2] != x[0]){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
  
  return 0;
}