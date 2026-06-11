#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

inline int isPrime(ll n){
  for(ll i = 2; i*i <= n; i++) if(n % i == 0) return 0;
  return 1;
}

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  vi num;
  for(int i = 2; i <= 55555; i++){
    if(isPrime(i)) num.push_back(i);
  }
  int n; cin >> n;
  int cnt = 0;
  for(auto x : num){
    if(x % 5 == 1){
      cout << x << " ";
      cnt++;
    }
    if(cnt == n) break;
  }
  // cout << "\n";
  return 0;
}
