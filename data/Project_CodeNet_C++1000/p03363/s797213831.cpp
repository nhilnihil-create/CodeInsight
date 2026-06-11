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
  map <ll, ll> sum_l;
  int N; cin >> N;
  vector <ll> A(N);
  rep(i, N) cin >> A[i];
  ll sum = 0;
  rep(i, N){
    sum +=A[i];
    sum_l[sum]++;
  }
  ll ans = 0;
  for (auto itr = sum_l.begin(); itr != sum_l.end(); itr++){
    ans += itr->second*(itr->second-1)/2;
    if (itr->first == 0){
      ans += itr->second;
    }
  }
  cout << ans <<endl;
}