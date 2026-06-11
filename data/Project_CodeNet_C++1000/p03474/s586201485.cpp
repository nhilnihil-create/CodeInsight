#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
 int a,b;
 cin >> a >> b;
 string s;
  cin >> s;
 bool ans = true;
 rep(i,s.size()){
   if(i != a && s.at(i) == '-') ans = false;
   else if(i == a && s.at(i) != '-') ans = false;
 }
 cout << (ans?"Yes":"No") << endl;
 }
