#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
 int n;
 cin >> n;
set<char> a;

 rep(i,n){
   char x;
   cin >>x ;
   a.insert(x);
 }
 if(a.size() == 3) cout << "Three" << endl;
 else cout << "Four" << endl;
 } 