#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int fir = max({a, b, c});
  int thr = min({a, b, c});
  int sec = a + b + c - fir- thr;
  int cnt = 0;
  cnt += sec - thr;
  cnt += fir - sec;
  cout << cnt  << endl;





}
