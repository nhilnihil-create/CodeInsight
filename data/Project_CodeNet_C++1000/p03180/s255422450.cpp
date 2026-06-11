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
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define fastio std::ios::sync_with_stdio(false)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define input_from_file  freopen("input.txt", "r", stdin);

const int INF = 1e18;

int n;
int arr[20][20];
int pre[1<<18];
int dp[1<<18];

void getans(int i,vector<int> &v,int score,int mask,int group){
  if(i == v.size()){
    dp[mask] = max(dp[mask],score+pre[group]);
    return;
  }
  getans(i+1,v,score,mask,group);
  getans(i+1,v,score,mask|(1<<v[i]),group|(1<<v[i]));
}

signed main(){

  //input_from_file;
  cin>>n;

  memset(arr,0,sizeof arr);
  memset(pre,0,sizeof pre);
  for(int i=0;i<(1<<n);i++) dp[i] = -1*INF;

  dp[0] = 0;
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++) cin>>arr[i][j];

  for(int mask=0;mask<(1<<n);mask++){
    for(int i=0;i<n;i++) if(mask&(1<<i)){
     for(int j=i+1;j<n;j++) if(mask&(1<<j))
      pre[mask] += arr[i][j];
    }
  }

  for(int mask=0;mask<(1<<n);mask++){
    vector<int> v;
    for(int i=0;i<n;i++) if(!(mask&(1<<i))) v.push_back(i);
    getans(0,v,dp[mask],mask,0);
  }

  cout<<dp[(1<<n)-1]<<endl;
}
