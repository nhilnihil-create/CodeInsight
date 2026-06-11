#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
int main(){
  string s;  cin >> s;
  string t="";
  rep(i,0,s.size()){
    if(s[i]!='x') t+=s[i];
  }
  string t2 = t;
  reverse(all(t2));
  if(t2 != t){
    cout << -1 << endl;
    return 0;
  }
  vector<int> v(t.size()+1,0);
  int ite = 0;
  rep(i,0,s.size()){
    int j=i;
    while(j<s.size() && s[j]=='x') j++;
    v[ite++] = j-i;
    i = j;
  }
  ll sum = 0;
  for(int i=0 ; i<v.size()/2 ; i++){
    sum += max(v[i], v[v.size()-i-1]) - min(v[i], v[v.size()-i-1]);
  }
  cout << sum << endl;
  return 0;
}
