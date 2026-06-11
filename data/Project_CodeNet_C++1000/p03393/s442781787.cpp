#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int cnt[26];
int main() {
  string s;
  cin >> s;
  string t = s;
  int n = sz(s);
  rep(i,n){
    int c = s[i]-'a';
    cnt[c]++;
  }
  rep(i,26){
    if(cnt[i] == 0){
      char ch = 'a'+i;
      cout<<s+ch<<endl;
      return 0;
    }
  }

  int id = 0;
  bool ok = false;
    while(sz(s) && !ok){
      if(s[sz(s)-1] == 'z'){
        s.pop_back();
        cnt[t[n-1-id]-'a'] = 0;
        id++;
      }
      else
      {
        s[sz(s)-1]++;
        int c = s[sz(s)-1]-'a';
        if(cnt[c] == 0) ok=true;
        //cout<<s<<endl;
      }
    }
  if(sz(s)==0){
    cout<<-1<<endl;
    return 0;
  }
  cout<<s<<endl;
  return 0;
}