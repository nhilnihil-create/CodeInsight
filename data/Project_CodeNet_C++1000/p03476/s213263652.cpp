#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int q;
  cin >> q;
  vector<int>s(100010);
  for(int i=1;i<=100000;i++){
    if(i&1 && is_prime(i) && is_prime((i+1)/2)) s[i]++;
  }
  rep(i,100005){
    s[i+1]+=s[i];
  }
  while(q--){
    int l,r;
    cin >> l >> r;
    l--;
    cout << s[r]-s[l] << endl;
  }
  return 0;
}
