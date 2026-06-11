#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
 
 
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-10;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


//ここから編集

int arr[62];
ll pows[43];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int N;
  ll K; cin >> N >> K;
  vector<ll> A(N);
  REP(i,N) cin >> A[i];

  pows[0] = 1;
  for(int i=1; i<43; i++){
    pows[i] = 2*pows[i-1];
  }
  REP(i,N){
    ll tmp = A[i];
    for(int j=0; j<60; j++){
      if(tmp%2 == 1){
        arr[j]++;
      }
      tmp /= 2;
    }
  }
  //for(int i=0; i<20; i++) cout << arr[i] << endl;

  ll ans = 0;
  for(int i=43; i>=0; i--){
    
    // 0を取った時
    ll s1 = arr[i] * pows[i];

    // 1を取ったとき
    ll s2 = (N - arr[i]) * pows[i];
    //cout << arr[i] << endl;
    if(K >= pows[i]){
      if(s1 >= s2){
        ans += s1;
      }else{
        ans += s2;
        K -= pows[i];
      }
    }else{
      ans += s1;
    }
  }
  cout << ans << endl;
  return 0;
}