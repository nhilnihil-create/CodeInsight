//~ #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//~ #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//~ #pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;
#define int ll
#define all(a) begin(a),end(a)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
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

const int N=1000005;

void solve(){
	int n;
	cin>>n;
	vector<pi>a(n);
	cin>>a;
	set<pair<int,int>>lef,rig;
	for(int i=0;i<n;i++){
		lef.insert({a[i].S,i});
		rig.insert({a[i].F,i});
	}
	ll ans=0;
	int lst=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			auto it=*lef.begin();
			lef.erase(it);
			rig.erase({a[it.S].F,it.S});
			if(lst>a[it.S].S||lst<a[it.S].F){
				ans+=abs(lst-it.F);
				lst=it.F;
			}
		}
		else{
			auto it=*--rig.end();
			rig.erase(it);
			lef.erase({a[it.S].S,it.S});
			if(lst>a[it.S].S||lst<a[it.S].F){
				ans+=abs(lst-it.F);
				lst=it.F;
			}
			
		}
	}
	ans+=abs(lst);
	for(int i=0;i<n;i++){
		lef.insert({a[i].S,i});
		rig.insert({a[i].F,i});
	}
	ll ans2=0;
	lst=0;
	for(int i=0;i<n;i++){
		if(i%2){
			auto it=*lef.begin();
			lef.erase(it);
			rig.erase({a[it.S].F,it.S});
			if(lst>a[it.S].S||lst<a[it.S].F){
				ans2+=abs(lst-it.F);
				lst=it.F;
			}
		}
		else{
			auto it=*--rig.end();
			rig.erase(it);
			lef.erase({a[it.S].S,it.S});
			if(lst>a[it.S].S||lst<a[it.S].F){
				ans2+=abs(lst-it.F);
				lst=it.F;
			}
		}
	}
	ans2+=abs(lst);
	cout<<max(ans,ans2);
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc=1;
  //cin>>tc;
  for(int _=0;_<tc;_++){
    // cout<<"Case #"<<_+1<<": ";
    solve();
    if(_!=tc-1){
      cout<<'\n';
    }
  }
}

