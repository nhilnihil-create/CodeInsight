#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  ll a, b; cin >> a >> b;

  ll tmp=b-a;
  
  cout << (1+tmp)*tmp/2-b << endl;
}
