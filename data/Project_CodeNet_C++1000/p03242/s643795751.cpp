#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  cin >> s;
  rep(i , 3){
    if(s[i] == '9'){
      s[i] = '1';
    }
    else{
      s[i] = '9';
    }
  }
  cout << s << endl;
  return 0;
}