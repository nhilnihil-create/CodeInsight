#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)

typedef long long ll;

int main(){
 int n, m, c, seikai = 0;
 cin >> n >> m >> c;
 vector<int> b(m, 0);
 rep(i, m) cin >> b.at(i);
 rep(i, n) {
   vector<int> a(m, 0);
   rep(j, m){
   cin >> a.at(j);
 }
 ll ans = c;
 rep(k, m){
   ans += a.at(k) * b.at(k);
 }
   if(ans >0) seikai++;
 }
cout << seikai;
}
