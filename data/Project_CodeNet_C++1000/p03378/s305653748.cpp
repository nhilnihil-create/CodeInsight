#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
 int n,m,x;
 cin >> n >> m >> x;
 int a = 0, b = 0;
 rep(i,m){
   int y;
   cin >> y;
   if(y < x) a++;
   else b++;
 }
 cout << min(a,b) << endl;
 
 } 