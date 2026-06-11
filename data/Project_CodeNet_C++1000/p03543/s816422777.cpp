#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
 int n;
  cin >> n;
  if (n == 1110 || (n%1111) < 10 || (n%1000)%111 == 0) {
    cout << "Yes" << endl;
  }
  else  {
    cout << "No" << endl;
  }
 return 0;
}