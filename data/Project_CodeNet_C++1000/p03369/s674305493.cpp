#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i) 
using namespace std;
using ll = long long;
int main() {
 string s;
 cin >> s;
 cout << 700 + ((s[0] == 'o') + (s[1] == 'o') + (s[2] == 'o')) * 100 << "\n";

}