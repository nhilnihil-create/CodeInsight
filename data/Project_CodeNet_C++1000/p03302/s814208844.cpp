#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int a,b;
  cin>>a>>b;
  if(a+b==15) cout << "+" << endl;
  else if(a*b==15)cout << "*" << endl;
  else cout << "x" << endl;
  return 0;
}

