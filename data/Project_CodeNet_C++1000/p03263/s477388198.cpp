#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vector<ll> > vvl;
typedef vector<vector<P> > vvp;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=998244353;
const int INF=1e9;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int h,w;
  cin >> h >> w;
  int f[h][w];
  rep(i,h){
    rep(j,w){
      cin >> f[i][j];
    }
  }
  vector<P>mae;
  vector<P>ato;
  rep(i,h){
    if(i%2==0){
      rep(j,w){
        if(f[i][j]%2==0)continue;
        if(j!=w-1){
          f[i][j]--;
          f[i][j+1]++;
          mae.push_back(P(i,j));
          ato.push_back(P(i,j+1));
        }
        else{
          if(i==h-1)continue;
          f[i][j]--;
          f[i+1][j]++;
          mae.push_back(P(i,j));
          ato.push_back(P(i+1,j));
        }
      }
    }
    else{
      for(int j=w-1;j>=0;j--){
        if(f[i][j]%2==0)continue;
        if(j!=0){
          f[i][j]--;
          f[i][j-1]++;
          mae.push_back(P(i,j));
          ato.push_back(P(i,j-1));
        }
        else{
          if(i==h-1)continue;
          f[i][j]--;
          f[i+1][j]++;
          mae.push_back(P(i,j));
          ato.push_back(P(i+1,j));
        }
      }
    }
  }
  cout << mae.size() << endl;
  rep(i,mae.size()){
    cout << mae[i].first+1 << " " << mae[i].second+1 << " " << ato[i].first+1 << " "<< ato[i].second+1 << endl;
  }
      
  return 0;     
}
