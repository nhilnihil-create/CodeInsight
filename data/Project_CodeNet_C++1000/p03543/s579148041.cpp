#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  string n;
  cin >> n;
  if((n[0]==n[1]&&n[1]==n[2])||(n[1]==n[2]&&n[2]==n[3])){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
    
}