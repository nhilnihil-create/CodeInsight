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

ll gcd(ll a,ll b){
  if(b == 0)return a;
  return gcd(b,a%b);
}
int main(){
  ll n,m;
  cin >> n >> m;
  string s,t;
  cin >> s >> t;

  ll lcm = n * (m / gcd(n,m));

  map<int,char> dict;
  for(int i = 0;i < n;i++){
    dict[i * (lcm / n) + 1] = '*';
  }

  for(int i = 0;i < m;i++){
    dict[i * (lcm / m) + 1] = '*';
  }

  for(int i = 0;i < n;i++){
    dict[i * (lcm / n) + 1] = s[i];
  }

  for(int i = 0;i < m;i++){
    if(dict[i * (lcm / m) + 1] == '*')dict[i * (lcm / m) + 1] = t[i];
    else if(dict[i * (lcm / m) + 1] != t[i]){
      cout << -1 << endl;
      return 0;
    }
  }

  cout << lcm << endl;
}