#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;

bool func(char c){
  if(c >= '0' && c <= '9')
    return true;
  else
    return false;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  rep(i, a){
    if(func(s[i]) == false){
      cout << "No" << endl;
      return 0;
    }
  }
  if(s[a] != '-') {
    cout << "No" << endl;
    return 0;
  }
  for(int i=b+1; i<s.length();i++){
     if(func(s[i]) == false){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}