#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  char x,y;
  cin >> x >> y;
  if(x<y){
    cout << "<" << endl;
  }
  else if(x==y){
    cout << "=" << endl;
  }
  else{
    cout << ">" << endl;
  }
    
}