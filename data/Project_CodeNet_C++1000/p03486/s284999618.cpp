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


int main()
{
  string S, T; cin >> S >> T;
  vector<int> si;
  for(auto x: S){
    si.push_back(x - '0');
  }
  int ssize = si.size();
 
  vector<int> ti;
  for(auto x: T){
    ti.push_back(x - '0');
  }
  int tsize = ti.size();

  int same = 0;
  vector<int> ps;
  rep(i, 0, ssize){
    rep(k, 0, tsize){
      if(si[i] < ti[k]){
        cout << "Yes" << endl;
        return 0;
      }
      if(find(ps.begin(), ps.end(), i) != ps.end()) continue;
        if(si[i] ==  ti[k]){
          ps.push_back(i);
          ++same;
      }
    }
  }

  if(same == ssize && ssize < tsize)cout << "Yes" << endl;
  else cout << "No" << endl;
}