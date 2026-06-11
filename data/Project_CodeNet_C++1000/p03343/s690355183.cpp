#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;
#define int ll
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

const int mod=1e9+7;

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

void solve(){
	int n,k,q;
	cin>>n>>k>>q;
	vi a(n);
	cin>>a;
	int ans=2e9;
	for(int x=0;x<n;x++){
		vi zz2;
		int cr=0;
		vector<vi>zz;
		debug(x);
		for(int j=0;j<n;j++){
			if(a[j]<a[x]){
				if(cr){
					zz.pb(zz2);
					zz2.clear();
				}
				cr=0;
			}
			else{
				zz2.pb(a[j]);
				cr++;
			}
		}
		if(cr){
			zz.pb(zz2);
		}
		debug(x);
		vi an;
		for(auto &i:zz){
			sort(all(i));
			debug(i,i.size()-k+1);
			for(int j=0;j<((int)i.size()-k+1);j++){
				an.pb(i[j]);
			}
		}
		debug(x);
		sort(all(an));
		if(an.size()<q){
			continue;
		}
		ans=min(ans,an[q-1]-a[x]);
	}
	cout<<ans;
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

