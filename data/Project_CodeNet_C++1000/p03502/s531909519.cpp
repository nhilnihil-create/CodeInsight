#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int m = n;
  int c = 0;
  while(n > 0){
    c += n % 10;
    n /= 10;
  }
  
  
  
  cout << (m % c == 0 ? "Yes" : "No") << endl;

  return 0;
}