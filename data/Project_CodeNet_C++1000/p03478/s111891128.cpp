#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int ssum(int x){
  int a = 0;
  while(x>0){
    a += x%10;
    x /= 10;
  }
  return a;
}

int main(){
  int N, A, B; cin >> N >> A >> B;
  int ans = 0;
  rep(i,N+1){
    int b =ssum(i);
    if( b >= A && b <= B) ans += i;
  }
  cout << ans << endl;
  return 0;
}