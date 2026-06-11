#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s;
  cin >> s;
  
  string ans = "";
  int minans = 1000;
  int n = s.size();
  rep(i,n-2){
    ans += s[i];
    ans += s[i+1];
    ans += s[i+2];
    if(abs(stoi(ans) - 753) < minans){
      minans = abs(stoi(ans) - 753);
    }//if
    ans = "";
  }
  
  cout << minans << endl;
}
