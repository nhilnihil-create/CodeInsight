#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
const int MAX=2e5;
const ll MOD=1e9+7;
const int INF=1<<30;

int main(){
  int N; cin >> N;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  ll ans=0;
  ll j=0;
  int XOR=a[0];
  rep(i,N){
    if(i>j){
      j=i;
      XOR=a[i];
    }
    while((XOR^a[j+1])==XOR+a[j+1]&&j<N-1){
      XOR+=a[j+1];
      j++;
    }
    ans+=j+1-i;
    XOR-=a[i];
  }
  cout << ans << endl;
}