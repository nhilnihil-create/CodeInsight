#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int a,b,x;
  cin >>a>>b>>x;
  if(a<=x&&x<=a+b){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  
}   