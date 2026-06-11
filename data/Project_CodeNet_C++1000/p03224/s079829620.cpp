#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
typedef long long int ll;
const ll  MOD = 1000000007;
typedef pair<ll,ll> P;
const ll INF = 100100100100100100;

ll N;
ll ans[1000][1000];

void func(ll cnt, ll start, ll repeat) {
  rep(i,repeat){
    ans[cnt][cnt+i] = start+i;
    ans[cnt+i+1][cnt] = start+i;
  }
}
int main(){
  cin >> N;
  ll K = 1;
  while(1){
    ll tmp = K * (K -1) / 2;
    if (tmp == N){
      break;
    }
    else if( tmp > N){
      cout << "No" << endl;
      return 0;
    }
    K++;
  }
  cout << "Yes" << endl;
  cout << K << endl;
  ll L = 2*N/K;

  ll start= 1;
  rep(i,K-1){
    func(i,start,K-1-i);
    start += K-i-1;
  }
  rep(i,K){
    cout << L;
    rep(j,L){
      cout << " " << ans[i][j];
    }
    cout << endl;
  }
}
