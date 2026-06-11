#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

string s;
int w;

int main() {
  cin >> s >> w;
  string ans;
  for(int i=0;i<s.size();i++){
    if(i%w==0) ans+=s[i];
  }
  cout << ans << endl;
} 