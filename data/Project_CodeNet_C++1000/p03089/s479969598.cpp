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
  int N; cin >> N;
  vector <int> a(N);
  rep(i, N) cin >> a[i];
  vector <int> ans;
  int posi;
  rep(i, N){
    posi = -1;
    rep(j, a.size()){
      if (a[j] == j + 1) posi = j + 1;
    }
    if (posi > 0){
      ans.push_back(posi);
      a.erase(a.begin() + posi-1);
    }
    else{
      break;
    }
  }
  if (posi == -1){
    cout << posi;
  }
  else{
    rep(i, N){
      cout << ans[N-i-1] <<endl;
    }
  }
}
