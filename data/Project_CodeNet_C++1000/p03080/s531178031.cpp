#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,a[10];
string s;

int main() {
  cin >> n >> s;
  int r=0;
  for(auto c:s){
    if(c=='R') r++;
  }
  cout << (r>n-r ? "Yes" : "No") << endl;
}