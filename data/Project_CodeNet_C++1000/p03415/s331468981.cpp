#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s[3];
  rep(i, 3){
    cin >> s[i];
  }
	
  cout << s[0][0] << s[1][1] << s[2][2] << endl;
  
  return 0;
}
