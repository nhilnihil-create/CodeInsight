#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
ll divisor(ll a,ll b){
  if(a % b == 0)return b;
  ll acopy = 0;
  acopy = a;
  a = b;
  b = acopy % b;
  divisor(a,b);
}
int main(){
  ll n,m;
  string s,t;
  cin >> n >> m >> s >> t;
  ll koubai = 0;
  koubai = n / divisor(n,m) * m;
  ll checkn = 0;
  checkn = koubai / m;
  ll checkm = 0;
  checkm = koubai / n;
  bool can = true;
  for(int i = 0;i <= n / checkn - 1;i++){
    if(s[checkn * i] != t[checkm * i])can = false;
  }
  if(can)cout << koubai << endl;
  else cout << -1 << endl;
}