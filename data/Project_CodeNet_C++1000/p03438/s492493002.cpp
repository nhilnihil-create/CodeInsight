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
  int N; cin >>N;
  ll b_a = 0;
  ll a_b = 0;
  ll a[N];
  ll b[N];
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];
  rep(i, N){
    if (a[i] >= b[i]) a_b += (a[i]-b[i]);
    else b_a += (b[i]-a[i])/2;
  }
  if (b_a >= a_b) cout << "Yes" << endl;
  else cout << "No" << endl;
}