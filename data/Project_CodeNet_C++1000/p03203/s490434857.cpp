#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX
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

vector<int>adj[N];
vector<int>adj2[N];
struct SegTree{
  vector<int>t;
  int _=1e9+100;
  int merge(int x,int y){
    return min(x,y);
  }
  SegTree(int n){
    t.resize(4*n);
    for(auto &i:t){
      i=_;
    }
  }
  
  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
      return _;
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(query(v*2, tl, tm, l, min(r, tm))
		 ,query(v*2+1, tm+1, tr, max(l, tm+1), r));
  }
  
  void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
      t[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
	update(v*2, tl, tm, pos, new_val);
      else
	update(v*2+1, tm+1, tr, pos, new_val);
      t[v] = merge(t[v*2],t[v*2+1]);
    }
  }
}; 


void solve(){
	int H,W,n;
	cin>>H>>W>>n;
	vector<pi>a(n);
	cin>>a;
	sort(all(a));
	for(int i=0;i<n;i++){
		if(a[i].F>=a[i].S){
			adj[a[i].F-a[i].S].pb(a[i].S);
			adj2[a[i].S].pb(a[i].F);
		}
	}
	for(int i=0;i<N;i++){
		sort(all(adj[i]));
		sort(all(adj2[i]));
	}
	int cr=0;
	//~SegTree st(n);
	//~for(int i=0;i<n;i++){
		//~st.update(1,0,n-1,i,a[i].S);
	//~}
	int ans=H,lst=0,waste=0;
	while(1){
		if(adj[cr].size()==0){
			while(lst<W){
				lst++;
				for(auto i:adj2[lst]){
					if(i-lst>=cr){
						ans=min(ans,i-1);
					}
				}
			}
			break;
		}
		else{
			int zz=adj[cr][0];
			cr++;
			while(lst<zz-1){
				lst++;
				for(auto i:adj2[lst]){
					if(i-lst>=cr-1){
						ans=min(ans,i-1);
					}
				}
			}			
		}		
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

