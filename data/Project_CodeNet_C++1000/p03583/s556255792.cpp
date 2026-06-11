#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n;
  cin >> n;
  for(int i=1;i<3501;i++) {
    for(int j=1;j<3501;j++) {
      if(4*i*j-i*n-j*n>0&&i*j*n%(4*i*j-i*n-j*n)==0) {
        cout << i << " " << j << " " << i*j*n/(4*i*j-i*n-j*n) << endl;
        return 0;
      }
    }
  }
}