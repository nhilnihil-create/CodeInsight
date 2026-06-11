#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll a = 0;
  string s; cin >> s;
  rep(i,s.size()){
    if(s[i] == '+'){
      a++;
    }
    else{
      a--;
    }
  }
  cout << a;
}
  