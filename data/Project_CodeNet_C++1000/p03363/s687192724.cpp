#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  ll cnt = 0;
  map<ll,ll> mp;
  mp[0] = 1;
  ll sum = 0;
  for(int i = 0;i < n;i++) {
    ll a;
    cin >> a;
    sum += a;
    cnt += mp[sum];
    mp[sum]++;
  }
  cout << cnt << endl;
}