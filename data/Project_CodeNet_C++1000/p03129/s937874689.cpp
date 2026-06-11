#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N,K;
  cin >> N >> K;

  string ans = "YES";
  if(N % 2 == 0) {
    if(K > N/2) ans = "NO";
  }else {
    if(K > N/2+1) ans = "NO";
  }
  
  cout << ans << endl;

}