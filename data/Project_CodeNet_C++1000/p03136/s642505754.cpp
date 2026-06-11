#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  vector<ll> m(n);
  ll wa = 0;
  for(int i = 0;i < n;i++){
    cin >> m[i];
    wa += m[i];
  }
  sort(m.begin(),m.end());
  wa -= m[n - 1];
  if(wa > m[n - 1])cout << "Yes" << endl;
  else cout << "No" << endl;
}