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
string digit_4(int n, int k){
  string s;
  int digit = 4;
  if(k==0){s="0";}
  while(k>0){
    s.push_back((k%digit)+'0');
    k -= k%digit;
    k /= digit;
  }

  while(s.size()<n){
    s.push_back('0');
  }
  return s;
}

int main(void) {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  arr(l,n);

  int ans=10000000;
  rep(i,pow(4,n)){
    string s=digit_4(n, i);

    int take[4]={};
    int tmp=0;
    rep(i,n){
      if(s[i]!='0' && take[s[i]-'0']>0) tmp+=10;
      take[s[i]-'0']+=l[i];
    }

    if(take[1]==0) continue; tmp+=abs(take[1]-a);
    if(take[2]==0) continue; tmp+=abs(take[2]-b);
    if(take[3]==0) continue; tmp+=abs(take[3]-c);

    //prt3(s, tmp, ans);
    ans=min(ans,tmp);
  }

  prt(ans);

}
