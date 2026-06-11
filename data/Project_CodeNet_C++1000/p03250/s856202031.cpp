#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl

int main(){
  int a, b, c;
  cin >> a >> b >>c;
  int M = max({a,b,c});
  int m = min({a,b,c});
  int sec = a+b+c-M-m;
  cout << 10*M+sec+m << endl;
}