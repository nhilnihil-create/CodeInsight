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
  ll n,m,x;
  cin >> n >> m >> x;
  ll mae = 0;
  ll ato = 0;
  for(int i = 0;i < m;i++){
    ll in = 0;
    cin >> in;
    if(in <= x)mae++;
    else ato++;
  }
  cout << min(mae,ato) << endl;
}