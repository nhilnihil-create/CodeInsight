#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
string s; cin >> s;
ll n=s.size();
ll cnt=0,d=n-1;
  for(ll i=n-1;i>=0;i--){
    if(s[i]=='B'){
      cnt+=d-i;
      d--;
    }
  }
  cout << cnt <<endl;
}
