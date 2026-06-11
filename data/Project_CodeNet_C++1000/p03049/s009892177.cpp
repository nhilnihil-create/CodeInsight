#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  int ab=0, bxa=0, bxx=0, xxa=0;
  rep(i,n) {
    string s;
    cin >> s;
    for(int j=0; j<s.size()-1; j++) {
      if(s[j]=='A'&&s[j+1]=='B') ab++;
    }
    if(s[0]=='B'&&s[s.size()-1]=='A') bxa++;
    else if(s[0]=='B') bxx++;
    else if(s[s.size()-1]=='A') xxa++;
  }
  if(bxa+xxa+bxx==0) {
    cout << ab << endl;
  }
  else if(xxa+bxx==0) {
    cout << ab+bxa-1 << endl;
  }
  else {
    cout << ab+bxa+min(xxa,bxx) << endl;
  }
  return 0;
}