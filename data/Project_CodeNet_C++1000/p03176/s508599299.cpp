#include "bits/stdc++.h"
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define show(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
#else
#define show(...) 42
#endif


#define f first
#define s second
#define endl "\n"
#define pb push_back
#define  oo 0x3f3f3f3f
#define limit 1000000007
#define int long long int
#define mod(x,m) ((x%m+m)%m)
#define ll long long
#define two pair<int,int>
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define fastio std::ios::sync_with_stdio(false)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define input_from_file  freopen("input.txt", "r", stdin);


const int N = 4e5;  // limit for array size
int t[2 * N];

void modify(int p, int value,int n) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p],t[p^1]);
}

int query(int l, int r,int n) {  // sum on interval [l, r]
  int res = 0;
  for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,t[l++]);
    if (r&1) res = max(res,t[--r]);
  }
  return res;
}

signed main(){
 //input_from_file;
 int n; cin>>n;
 int ans = 0;
 vector<int> h(n), a(n);
 for(int i=0;i<n;i++) cin>>h[i];
 for(int i=0;i<n;i++) cin>>a[i];
 memset(t,0,sizeof t);
 for(int i=0;i<n;i++){
   int curr = a[i] + query(0,h[i]-1,n+1);
   ans = max(ans,curr);
   modify(h[i],curr,n+1);
 }
 cout<<ans<<endl;
}
