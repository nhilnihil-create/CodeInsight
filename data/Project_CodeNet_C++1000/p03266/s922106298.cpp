#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  ll a = 0, b = 0, c = 0;
  vector<ll> num(k);
  for(int i = 1 ; i <= n; ++i){
    num[i%k]++;
  }

  if(k % 2){
    ans += pow(num[0], 3);
  } else {
    ans += pow(num[0], 3);
    ans += pow(num[k / 2], 3);
  }

  cout << ans << endl;
}