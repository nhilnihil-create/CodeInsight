#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  string s;
  if (n == 0){
    cout << 0 << endl;
    return 0;
  }
  while(n){
    int p = abs(n % (-2));
    if (n < 0 && n % 2 != 0) n = n / (-2) + 1;
    else n /= (-2);
    s += '0' + p;
  }
  rep(i, s.size()) cout << s[s.size() - 1 - i];
  cout << endl;
}