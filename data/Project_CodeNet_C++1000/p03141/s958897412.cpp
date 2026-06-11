#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin >> n;
  priority_queue<pair<ll,pair<ll,ll>>> que;
  ll sum1 = 0;
  ll sum2 = 0;
  for(int i = 0;i < n;i++){
    ll a,b;
    cin >> a >> b;
    que.push(make_pair(a+b,make_pair(a,b)));
  }

  for(int i = 0;i < n;i++){
    pair<ll,pair<ll,ll>> p = que.top();
    que.pop();
    if(i % 2 == 0)sum1 += p.second.first;
    else sum2 += p.second.second;
  }

  cout << sum1 - sum2 << endl;
}