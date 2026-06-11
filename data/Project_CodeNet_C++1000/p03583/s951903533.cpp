#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N;
  cin>>N;
  bool ok = false;
  for(ll h = 1; h <=3500;h++){
    for(ll n = 1; n <= 3500; n++){
      if(4LL*h*n-N*n-h*N>0&&N*h*n%(4LL*h*n-N*n-h*N)==0){
        cout<<h<<" "<<n<<" "<<N*h*n/(4LL*h*n-N*n-h*N)<<endl;
        ok=true;
        break;
      }
    }
    if(ok) break;
  }
}