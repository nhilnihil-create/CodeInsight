#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    int N; cin >> N;
    vi D(N); rep(i,N) cin >> D[i];
    int M; cin >> M;
    vi T(M); rep(i,M) cin >> T[i];
    if(M > N) {cout << "NO";return 0;}
    sort(D.begin(),D.end()); 
    sort(T.begin(),T.end()); 
  
    bool ans = true;
    int tmp=0;
    rep(i,M){
      while(tmp < N-1 && D[tmp] < T[i]) tmp++;
      if(tmp < N && D[tmp] == T[i]){ tmp++;continue;
      }else{ans = false; break;}
      
    }
  
    cout << (ans?"YES":"NO");
    return 0;
}
