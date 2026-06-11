#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll N;
  cin >> N;
  vector<tuple<string,ll,ll>> A(N);
  rep(i,N){
    cin >> get<0>(A.at(i)) >> get<1>(A.at(i));
    get<1>(A.at(i))=100-get<1>(A.at(i));
    get<2>(A.at(i))=i+1;
  }
  sort(all(A));
  rep(i,N){
    cout << get<2>(A.at(i)) << endl;
  }
}
      
    