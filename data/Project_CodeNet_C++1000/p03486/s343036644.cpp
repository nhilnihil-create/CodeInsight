#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1e19;
#define all(v) v.begin(), v.end()

int main(){
  string A,B;
  cin >> A >> B;
  sort(all(A));
  sort(all(B));
  reverse(all(B));
  if(A<B){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
}
      