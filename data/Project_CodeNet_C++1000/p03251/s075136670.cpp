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
  ll n,m,x,y;
  cin >> n >> m >> x >> y;
  vector<ll> a(n);
  vector<ll> b(m);
  for(int i = 0;i < n;i++)cin >> a[i];
  sort(a.rbegin(),a.rend());
  for(int i = 0;i < m;i++)cin >> b[i];
  sort(b.begin(),b.end());
  for(int i = a[0] + 1;i <= b[0];i++){
    if(i > x && i <= y){
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
}