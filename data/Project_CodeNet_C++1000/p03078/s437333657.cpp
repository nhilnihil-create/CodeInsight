#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>

#define rep(i,n)         for(int i=(int)0; i<(int)n; i++)
#define REP(i,m,n)       for(int i=(int)m; i<(int)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define prt(var)         cout << var << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(var)      rep(i,var.size()){cout << var[i] << " ";} cout << "\n"

//----------------------------------------------------------------
struct id{
  int num1, num2, num3;
};

int main(void) {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  arrll(a,x);
  arrll(b,y);
  arrll(c,z);

  sort(all(a), greater<ll>());
  sort(all(b), greater<ll>());
  sort(all(c), greater<ll>());

  vecll taste;
  rep(l,x){
    rep(m,y){
      rep(n,z){
        if((l+1)*(m+1)*(n+1)<=k){
          taste.push_back(a[l]+b[m]+c[n]);
        } else {
          break;
        }
      }
    }
  }

  sort(all(taste),greater<ll>());
  rep(i,k){
    prt(taste[i]);
  }


}
