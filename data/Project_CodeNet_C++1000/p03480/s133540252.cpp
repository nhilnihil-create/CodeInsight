#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
ll MOD = 1000000007;
ll INF = 2147483647;
double EPS = 1e-12;
double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

int main(){
  string S;cin >> S;
  int N = S.size();
  int ans = 100000000;
  rep(i,N-1){
    if(S[i] != S[i+1]){
      ans = min((ll)ans,max(i+1,N-i-1));
    }
  }
  if(ans == 100000000){
    cout << N << endl;
    return 0;
  }
  cout << ans << endl;
}