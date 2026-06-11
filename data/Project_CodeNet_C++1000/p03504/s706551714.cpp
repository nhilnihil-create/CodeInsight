#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define vl vector<ll>
#define vs vector<string>
#define vll vector< vector<ll> >
#define pll pair<ll,ll>
#define pls pair<ll,string>
#define psl pair<string,ll>
#define tll tuple<ll, ll, ll>
#define vp vector< pair<ll,ll> >
#define vt vector< tuple<ll, ll, ll> >
#define all(c) c.begin(),c.end()

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
 
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;

//command
//c++ atcoder.cpp -std=c++14
//./a.out

//cout << setprecision(12) << ans << endl;

#define NN 2020202

int main(){
  ll n, C;
  cin >> n >> C;
  vt vec;
  ll s, t, c;
  for (int i=0;i<n;i++){
    cin >> s >> t >> c;
    vec.push_back(tll(s,t,c));
  }

  sort(vec.begin(), vec.end());

  ll ans = 0;
  bool flag;
  pll ch[C];
  ch[0] = pll(get<1>(vec[0]), get<2>(vec[0]));

  for (int i=1;i<n;i++){
    flag = false;
    for (int j=0;j<=ans;j++){
      if (ch[j].first <= get<0>(vec[i]) && ch[j].second == get<2>(vec[i])){
        ch[j].first = get<1>(vec[i]);
        ch[j].second = get<2>(vec[i]);
        flag = true;
        break;
      }
      else if (ch[j].first < get<0>(vec[i]) && ch[j].second != get<2>(vec[i])){
        ch[j].first = get<1>(vec[i]);
        ch[j].second = get<2>(vec[i]);
        flag = true;
        break;
      }
    }
    if (!flag){
      ch[ans+1].first = get<1>(vec[i]);
      ch[ans+1].second = get<2>(vec[i]);
      ans += 1;
    }

    //for (int j=0;j<=ans;j++) cout << ch[j].first << " ";
    //cout << endl;
  }

  cout << ans+1 << endl;
}