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
  string s;
  cin >> s;
  ll len, w, ans;
  if (s.length()%2 == 0){
    len = s.length()/2;
    w = 0;
    while (w<len && s[len-1-w] == s[len-w] && s[len+w-1] == s[len+w]) w += 1;
    ans = len + w;
  }
  else if (s.length()%2 == 1){
    len = (s.length()-1)/2;
    w = 1;
    while (w<=len && s[len-w] == s[len-w+1] && s[len+w-1] == s[len+w]) w += 1;
    ans = len + w;
  }

  cout << ans << endl;
}