#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
 int n,a,b;
 cin >> n >> a >> b;
 int ans = 0;
 for(int i =1 ; i <= n; i++){
 int sum = i%10;
   int t = i;
 while(t >= 10){
   t /= 10;
   sum += t%10;
 }
 if(sum >= a && sum <= b) ans+=i;
}
 cout << ans << endl;
 }
