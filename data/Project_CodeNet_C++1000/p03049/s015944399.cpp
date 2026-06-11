#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

//部分文字列の個数を検索
int find(string s,string keyword){
  int count = 0;
  string::size_type pos = s.find(keyword);
  while(pos != string::npos){
    count++;
    pos = s.find(keyword,pos+keyword.length());
  }
  return count;
}

int main() { 
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  
  int ans = 0,ab=0,a=0,b=0;
  rep(i,n){
    if(s[i].back() == 'A' && s[i].front() == 'B') ab++;
    else if(s[i].back() == 'A') a++;
    else if(s[i].front() == 'B') b++;
    ans+=find(s[i],"AB");
  }
  int m = min(a,b);
  if(a || b){
    m = m + ab;
  }
  else m=max(0,ab-1);
  ans = ans+m;
  cout<<ans<<endl;
  

  return 0;
}