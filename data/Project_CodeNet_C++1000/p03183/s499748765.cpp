#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin >> N;
  vector<int> w(N),s(N),v(N);
  for(int i=0;i<N;i++){
    cin >> w.at(i) >> s.at(i) >> v.at(i);
  }

  vector<pair<int,int>> xi(N);
  for(int i=0;i<N;i++)  xi.at(i)=mp(s.at(i)+w.at(i),i);
  sort(all(xi));
  vector<vector<ll>> dp(N+1,vector<ll>(1e5,0));
  for(int i=1;i<N+1;i++){
    int now=xi.at(i-1).se;
    int wi=w.at(now);
    int si=s.at(now);
    ll vi=v.at(now);
    //cout << wi << "," << si << "," << vi << endl;
    for(int j=0;j<1e5;j++){
      dp.at(i).at(j)=dp.at(i-1).at(j);
      if(0<=j-wi && j-wi<=si) chmax(dp.at(i).at(j),dp.at(i-1).at(j-wi)+vi);
    }
    //for(int j=0;j<10;j++) cout << dp.at(i).at(j) << " ";cout << endl;
  }
  ll ans=0;
  for(int i=0;i<1e5;i++)  chmax(ans,dp.at(N).at(i));
  cout << ans << endl;

  return 0;
}