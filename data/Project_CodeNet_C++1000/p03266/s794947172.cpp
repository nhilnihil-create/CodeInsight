#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
using Graph = vector<vector<int>>;


int main() {
  ll n, k; cin >> n >> k;
  if(2*n < k){
    cout << 0 << endl;
    return 0;
  }
  if(k%2 != 0){
    ll a = n/k;
    cout << a*a*a << endl;
  }else{
    ll a = n/k; 
    ll b = (n-k/2)/k+1;
    cout << a*a*a + b*b*b << endl;
  }

  return 0;
}
