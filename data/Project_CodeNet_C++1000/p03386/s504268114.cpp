#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
 int a,b,k;
 cin >> a >> b >>k ;
 for(int i = a; i <= b; i++){
   if(i <= a+k-1 || i >= b - k + 1) cout << i << endl;
 }
 } 