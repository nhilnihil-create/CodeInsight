#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  string s;
  cin >> s;
  int k = s.size();
  
  int l = 0;
  rep(i, k) if(s[i] == 'x') l++;
  
  if(l <= 7) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}