#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll A, B, K;
  cin >> A >> B >> K;

  set<ll> nums;

  rep(i, K){
    if(A + i > B) break;
    nums.insert(A + i);
  }
  rep(i, K){
    if(B - i < A) break;
    nums.insert(B - i);
  }

  for(auto it = nums.begin(); it != nums.end(); it++)
    cout << (*it) << endl;
  
  return 0;
}
