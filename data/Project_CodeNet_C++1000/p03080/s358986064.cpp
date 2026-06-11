#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main() {
  int N;
  string s;
  cin>>N>>s;
  int cntr(0),cntb(0);
  for(int i(0);i<N;i++){
    if(s[i] == 'R') cntr++;
    if(s[i] == 'B') cntb++;
  }
  if(cntr > cntb) cout << "Yes" << endl;
  else cout << "No" << endl;
}