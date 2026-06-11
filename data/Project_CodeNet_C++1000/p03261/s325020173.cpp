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
  string s;
  char t;
  map<string, int> mp;
  rep(i, n){
    cin >> s;
    mp[s]++;
    if(mp[s] == 2){
      cout << "No" << endl;
      return 0;
    }
    if(i > 0){
      if(t != s[0]){
        cout << "No" << endl;
      	return 0;
      }
    }
    t = s[s.size() - 1];
  }
     
  cout << "Yes" << endl;
  return 0;
}