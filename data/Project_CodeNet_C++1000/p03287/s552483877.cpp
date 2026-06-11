#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  ll n, m;
  cin >> n >> m;
  vll a(n);
  rep (i, n){cin >> a[i];}
  map<ll, ll> b;
  ll sum = 0;
  rep (i, n){
    sum += a[i];
    int x_temp = sum % m;
    if (b.find(x_temp) != b.end()){
      b[x_temp]++;
    }else{
      b[x_temp] = 1;
    }
  }
  ll ans = 0;
  for (auto i : b){
    if (i.first == 0){
      ans += (i.second + i.second*(i.second-1)/2);
    }else{
      ans += i.second*(i.second-1)/2;
    }
  }
  cout << ans << endl;
}
    