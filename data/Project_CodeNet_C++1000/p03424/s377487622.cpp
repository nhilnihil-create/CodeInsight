#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  char s[n];
  rep(i,n) cin >> s[i];
  
  rep(i,n){
    if(s[i] == 'Y'){
      cout << "Four" << endl;
      return 0;
    }
  }
  
  cout << "Three" << endl;
}