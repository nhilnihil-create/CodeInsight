#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s, t;
  cin >> s >> t;
  rep(i, 3){
    if(s[i] != t[2 - i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
              
                                                                                               
                                                                                               
  
  return 0;
}
