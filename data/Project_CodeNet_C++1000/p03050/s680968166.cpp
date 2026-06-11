#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
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
  ll N; cin >> N;
  ll i = 1;
  ll ans = 0;
  while (i*i < N){
    if (N % i == 0){
      ll m = N/i-1;
      if (m > i){
        ans += m;
      }
    }
    i++;
  }
  cout << ans << endl;
}
  