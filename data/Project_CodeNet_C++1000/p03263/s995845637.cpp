#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec              vector<int>
#define vecll            vector<ll>
#define vecd             vector<double>
#define vecst            vector<string>
#define vecb             vector<bool>
#define v2(v,n,m,init)   vector<vector<int>>  v(n, vector<int>(m, init))
#define vb2(v,n,m,init)  vector<vector<bool>> v(n, vector<bool>(m, init))
#define vll2(v,n,m,init) vector<vector<ll>>   v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//------------------------------------------------------------------
#define prt4(v1, v2, v3, v4) cout << (v1) << " " << (v2) << " " << (v3) << " " << (v4) << "\n"

int main(void){
  int h, w;
  cin >> h >> w;
  v2(a, h, w, 0);
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }

  vector<vector<int>> ans;
  rep(i,h){
    rep(j,w-1){
      vector<int> tmp;
      if(a[i][j]%2==1){
        a[i][j]--;
        a[i][j+1]++;
        tmp.push_back(i+1);
        tmp.push_back(j+1);
        tmp.push_back(i+1);
        tmp.push_back(j+2);
      }
      if(tmp.size()==4) ans.push_back(tmp);
    }
  }

  rep(i,h-1){
    vector<int> tmp;
    if(a[i][w-1]%2==1){
      a[i][w-1]--;
      a[i+1][w-1]++;
      tmp.push_back(i+1);
      tmp.push_back(w);
      tmp.push_back(i+2);
      tmp.push_back(w);
    }
    if(tmp.size()==4) ans.push_back(tmp);
  }

  prt(ans.size());
  rep(i,ans.size()){
    prt4(ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
  }
}
