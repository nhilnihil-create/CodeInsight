//~#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//~#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//~#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;

#define all(a) begin(a),end(a)
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int mod=10243;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int mul(int a,int b){
  return ((a)*1ll*(b))%mod;
}

void add(int &a,int b){
  a+=b;
  if(a>=mod)a-=mod;
}

int sub(int a,int b){
  a-=b;
  if(a<0){
    a+=mod;
  }
  return a;
}

int powz(int a,int b){
  int res=1;
  while(b){
    if(b&1){
      res=mul(res,a);
    }
    b/=2;
    a=mul(a,a);
  }
  return res;
}

template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
  input>>x.F>>x.S;
  return input;
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}

template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}

template<typename T>
vector<pair<T,int>> getvec(int n){
  vector<pair<T,int>>a(n);
  for(int i=0;i<a.size();i++){
    cin>>a[i].F;
    a[i].S=i;
  }
  return a;
}

void clr(auto &a,int n){
  a.clear();
  a.resize(n);
}

void unq(auto &a){
  sort(all(a));
  a.resize(unique(all(a))-a.begin());
}

const int N=200005;

int dp[N][2];
vector<int>adj[N];

void solve(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
		dp[x][s[y]-'A']++;
		dp[y][s[x]-'A']++;
	}
	queue<int>q;
	vector<int>vis(n);
	for(int i=0;i<n;i++){
		if(min(dp[i][0],dp[i][1])==0){
			vis[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int tp=q.front();
		q.pop();
		for(auto i:adj[tp]){
			dp[i][s[tp]-'A']--;
			if(dp[i][s[tp]-'A']==0&&vis[i]==0){
				q.push(i);
				vis[i]=1;
			}
		}
	}
	int tot=0;
	for(auto i:vis){
		tot+=i;
	}
	if(tot!=n){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	
	
	
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc=1;
  //~cin>>tc;
  for(int _=0;_<tc;_++){
    // cout<<"Case #"<<_+1<<": ";
    solve();
    if(_!=tc-1){
      cout<<'\n';
    }
  }
}

