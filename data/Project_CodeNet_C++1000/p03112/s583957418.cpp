#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec     vector<int>
#define vecll   vector<ll>
#define vec2    vector<vector<int>>
#define vec2ll  vector<vector<ll>>
#define vpair   vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define mpair(v1, v2)    make_pair(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << var << "\n"
#define scn(var)         cin >> var;
#define pYes()           prt("Yes")
#define pNo()            prt("No")
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(var)      rep(i,var.size()){cout << var[i] << " ";} cout << "\n"

//----------------------------------------------------------------
int main(void) {
  int a, b, q;
  cin >> a >> b >> q;
  arrll(s,a);
  arrll(t,b);
  arrll(x,q);

  //prtall(s);
  //prtall(t);
  //prtall(x);

  rep(i,q){
    //prt3(i, "start->", x[i]);
    auto it_a = upper_bound(all(s), x[i]);
    auto it_b = upper_bound(all(t), x[i]);

    int jinja_right = it_a - s.begin();
    int tera_right = it_b - t.begin();

    ll j_left, j_right, t_left, t_right;
    if(jinja_right==0){
      j_right = s[jinja_right];
      j_left = -3e10;
    } else if(jinja_right==a){
      j_right = 3e10;
      j_left = s[jinja_right-1];
    } else {
      j_right = s[jinja_right];
      j_left = s[jinja_right-1];

    }
    if(tera_right==0){
      t_right = t[tera_right];
      t_left = -3e10;
    } else if(tera_right==b){
      t_right = 3e10;
      t_left = t[tera_right-1];
    } else {
      t_right = t[tera_right];
      t_left = t[tera_right-1];
    }

    //prt2(j_left, j_right);
    //prt2(t_left, t_right);

    ll cond1 = min((x[i] - min(j_left, t_left)), max(j_right, t_right) - x[i]);
    ll cond2 = min(2*(x[i]-j_left)+t_right-x[i],2*(j_right-x[i])+x[i]-t_left);
    ll cond3 = min(2*(x[i]-t_left)+j_right-x[i],2*(t_right-x[i])+x[i]-j_left);
    ll ans = min(cond1, min(cond2, cond3));

    //prt2("Ans--->", ans);
    prt(ans);
  }

}
