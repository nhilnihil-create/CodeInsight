#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
//#define P pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;


ll
calc(dvec arr, int N, int M, bool plus)
{
  ll bet = 0;
  ll del = 0;
  ll pop = 0;
  if(plus){
    rep(i, 0, M){
      bet += arr[i][0];
      del += arr[i][1];
      pop += arr[i][2];
    }

  } else {
    for(ll i = N - 1; i >= N - M; --i){
      bet += arr[i][0];
      del += arr[i][1];
      pop += arr[i][2];
    }
  }

  return abs(bet) + abs(del) + abs(pop);

}

int main()
{
  int N, M; cin >> N >> M;
  vector<vector<ll>> arr(N);
  rep(i, 0, N){
    ll x, y, z; cin >> x >> y >> z;
    arr[i].push_back(x);
    arr[i].push_back(y);
    arr[i].push_back(z);
  }
  

  ll ans = 0;
  for(ll bit = 0; bit < (1 << 3); ++bit){
    vector<ll> comp(N, 0);
    rep(i, 0, N){
      rep(k, 0, 3){
        if(bit & (1 << k)) comp[i] += arr[i][k];
        else comp[i] += -arr[i][k];
      }
    }

    ll sum = 0;
    sort(comp.begin(), comp.end(), greater<ll>());
    rep(i, 0, M){
      sum += comp[i];
    }
    if(ans < sum) ans = sum;
  }

  cout << ans << endl;

}
