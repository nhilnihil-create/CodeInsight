#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  string s;
  cin>>s;
  if(int(s.size()) == 2) cout << s << endl;
  else {
    reverse(s.begin(),s.end());
    cout << s << endl;
  }
  return 0;
}

