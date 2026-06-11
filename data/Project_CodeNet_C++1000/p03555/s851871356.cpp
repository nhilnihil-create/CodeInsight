#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  // cout << s2;
  int n = s1.size();

  rep(i,n){
    if(s1.at(i) != s2.at(n-i-1)){
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
