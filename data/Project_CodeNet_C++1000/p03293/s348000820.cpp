#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef long double ld;

int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s,t;
  cin>>s>>t;
  for(int i = 0; i < s.length();i++){
    char last = s[s.length()-1];
    s.pop_back();
    s = last + s.substr(0, s.length());
    if(s == t) {
      cout << "Yes" << endl;
      return 0;
    }
  }  
  cout << "No" << endl;
  return 0;
}