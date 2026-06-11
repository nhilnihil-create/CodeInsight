#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
 int n,d,x;
 cin >> n >> d >> x;
 vector<int> a(n);
 rep(i,n) cin >> a.at(i);

 int ans= 0;
 rep(i,n){
   int b=1;
   while(b <= d){
     ans++;
     b+=a.at(i);
   }
 }
 cout << ans+x << endl;
 } 