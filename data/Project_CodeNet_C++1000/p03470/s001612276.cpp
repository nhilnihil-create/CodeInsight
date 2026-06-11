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
  map<ll,ll> a;
  for(int i = 0;i < n;i++){
    ll in;
    cin >> in;
    a[in]++;
  }
  cout << a.size() << endl;
}