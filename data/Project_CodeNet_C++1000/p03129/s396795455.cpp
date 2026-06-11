#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k;  
string s;

int main() {
  cin >> n >> k;
  cout << ((n+1)/2>=k?"YES":"NO") << endl;
}