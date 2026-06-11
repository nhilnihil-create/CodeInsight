#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(void){
  int n;
  cin >> n;
  int cnt = 0;
  int a = n;
  while (a > 0) {
    int s = a % 10;
    cnt += s;
    a /= 10;
  }
  
  if (n % cnt == 0)  cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
