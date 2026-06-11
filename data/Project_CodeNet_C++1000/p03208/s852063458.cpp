#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

struct Jewel {
    int value;
    int cost;
};
int main()
{
  ll N, K;
  cin>>N>>K;
  vector<ll> P;
  for(int i=0;i<N;i++){
    ll ai;
    cin>>ai;
    P.push_back(ai);
  }
  sort(P.begin(), P.end());
  ll ans=INT_MAX;
  for(int i=0;i<=N-K;i++){
   ans=min(ans, P[i+K-1]-P[i]);
  }
  cout<<ans<<endl;
}
