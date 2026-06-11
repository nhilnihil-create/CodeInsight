//~#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//~#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//~#pragma GCC target("avx2")  //Enable AVX
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

bool check(int mid,vector<int>&a){
	int n=a.size();
	vector<pair<int,int>>cr;
	cr.pb({0,a[0]});
	int i=1;
	while(i<n){
		int vl=a[i-1];
		if(vl==a[i]){
			if(cr.back().F==mid-1){
				if(cr.size()==1){
					return false;
				}
				pair<int,int>zz=cr.back();
				cr.pop_back();
				pi zz2=cr.back();
				cr.pop_back();
				if(zz2.S!=1){
					if(cr.size()&&cr.back().S==zz2.F){
						cr.back().S+=zz2.S-1;
					}
					else{
						cr.push_back({zz2.F,zz2.S-1});
					}
				}
				if(cr.size()&&cr.back().F==zz2.F+1){
					cr.back().S+=1;
				}
				else{
					cr.push_back({zz2.F+1,1});
				}
				if(cr.size()&&cr.back().F==0){
					cr.back().S+=zz.S;
				}
				else{
					cr.push_back({0,zz.S});
				}
			}
			else{
				pi zz=cr.back();
				cr.pop_back();
				if(zz.S!=1){
					if(cr.size()&&cr.back().F==zz.F){
						cr.back().S+=zz.S-1;
					}
					else{
						cr.push_back({zz.F,zz.S-1});
					}
				}
				if(cr.size()&&cr.back().F==zz.F+1){
					cr.back().S+=1;
				}
				else{
					cr.push_back({zz.F+1,1});
				}
			}
		}
		else if(a[i]>vl){
			if(cr.back().F==0){
				cr.back().S+=a[i]-vl;
			}
			else{
				cr.push_back({0,a[i]-vl});
			}
		}
		else{
			ll crsum=0;
			vector<pi>nwcr;
			for(int j=0;j<cr.size();j++){
				if(crsum+cr[j].S>=a[i]){
					if(cr[j].F==mid-1){
						if(nwcr.size()){
							pi zz=nwcr.back();
							nwcr.pop_back();
							if(zz.S>1){
								nwcr.push_back({zz.F,zz.S-1});
							}
							if(nwcr.size()&&nwcr.back().F==zz.F+1){
								nwcr.back().S+=1;
							}
							else{
								nwcr.push_back({zz.F+1,1});
							}
							ll dif=a[i]-crsum;
							if(nwcr.back().F!=0){
								nwcr.back().S+=dif;
							}
							else{
								nwcr.push_back({0,dif});
							}
						}
						else{
							return false;
						}
					}
					else{
						ll dif=a[i]-crsum;
						if(dif>1){
							nwcr.pb({cr[j].F,dif-1});
						}
						if(nwcr.size()&&nwcr.back().F==cr[j].F+1){
							nwcr.back().S+=1;
						}
						else{
							nwcr.pb({cr[j].F+1,1});
						}
					}
					break;
				}
				else{
					nwcr.pb({cr[j]});
					crsum+=cr[j].S;
				}
			}
			cr=nwcr;
		}
		i++;
	}
	return true;
}

void solve(){
	int n;
	cin>>n;
	vi a(n);
	cin>>a;
	vector<int>zz=a;
	sort(all(zz));
	zz.resize(unique(all(zz))-zz.begin());
	if(zz==a){
		cout<<1;
		return;
	}
	int l=2,r=n,ans=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,a)){
			ans=min(ans,mid);
			r=mid-1;
		}
		else{
			l=mid+1;
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

