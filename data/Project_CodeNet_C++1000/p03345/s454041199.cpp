#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vvi = vector<vector<int>> ;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI 3.141592653
#define rep(i, n) for(ll i = 0; i < n; i++)

int main(){
  ll a, b, c, k;
  cin >> a >> b >> c >> k;

  ll ans = a-b;
  ll amari = k % 2;

  if(amari == 0){
    cout << ans << endl;
  }
  else{
    cout << ans * (-1) << endl;
  }
}       