#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  char c;
  int a = 700;
  rep(i,3){
    cin >> c;
    if(c == 'o') a+=100;
  }
  cout << a << endl;
  return 0;
}
