#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec                vector<int>
#define vecll              vector<ll>
#define vecd               vector<double>
#define vecst              vector<string>
#define vecb               vector<bool>
#define vec2(var, n, m)    vector<vector<int>>  var(n, vector<int>(m, INF))
#define vecb2(var, n, m)   vector<vector<bool>> var(n, vector<bool>(m, false))
#define vecll2(var, n, m)  vector<vector<ll>>   var(n, vector<ll>(m, 0))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define f_sum(var)       accumulate(all(var), 0)
#define f_sumll(var)     accumulate(all(var), 0LL)
#define chmin(v1, v2)    v1 = min(v1, v2)
#define chmax(v1, v2)    v1 = max(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt(ok ? "YES" : "NO");}
//----------------------------------------------------------------

int main(void) {
  int n;
  cin >> n;
  arr(a,n);

  map<int, int> odd, even;
  rep(i,n){
    if(i&1) even[a[i]]++;
    else odd[a[i]]++;
  }
  int odd_id=-1, odd_mx=0, even_id=-1, even_mx=0;
  int odd_id2=-1, odd_mx2=0, even_id2=-1, even_mx2=0;
  for(auto i : odd){
    if(odd_mx<i.second){
      odd_id2=odd_id, odd_mx2=odd_mx;
      odd_id=i.first, odd_mx=i.second;
    } else if(odd_mx2<i.second){
      odd_id2=i.first, odd_mx2=i.second;
    }
  }
  for(auto i : even){
    if(even_mx<i.second){
      even_id2=even_id, even_mx2=even_mx;
      even_id=i.first, even_mx=i.second;
    } else if(even_mx2<i.second){
      even_id2=i.first, even_mx2=i.second;
    }
  }

  if(odd_id!=even_id){
    prt(n-odd_mx-even_mx);
  } else {
    prt(min(n-odd_mx2-even_mx, n-odd_mx-even_mx2));
  }
}
