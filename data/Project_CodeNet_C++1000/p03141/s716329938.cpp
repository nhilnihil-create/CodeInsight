#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> cnt(n);
  ll sum = 0;
  rep(i,n){
    int a,b; cin >> a >> b;
    cnt[i] = a+b;
    sum += b;
  }
  sort(all(cnt),greater<int>());
  ll first = 0;
  rep(i,n) if(i % 2 == 0) first += cnt[i];
  cout << first-sum;
  cout << "\n";
  return 0;
}
