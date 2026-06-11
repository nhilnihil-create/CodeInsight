#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int a,b,t;
  cin >> a >>b >>t;
  int time=1;
  int ans=0;
  while(a*time<=t){
    ans+=b;
    time++;
  }
  cout << ans << endl;
}