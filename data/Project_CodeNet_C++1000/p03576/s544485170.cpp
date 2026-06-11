#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const double eps = 1e-11;
const int inf = 1ll << 62;

int x[55],y[55];

signed main(){
	int n,K;cin>>n>>K;
	rep(i,n)cin>>x[i]>>y[i];
	vector<int>xa,ya;
	rep(i,n){
		xa.push_back(x[i]);
		ya.push_back(y[i]);
		}
	sort(xa.begin(),xa.end());
	sort(ya.begin(),ya.end());
	int res=inf;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			rep(k,n){
				for(int l=k+1;l<n;l++){
					int cnt=0;
					rep(m,n){
						if(xa[i]<=x[m]&&x[m]<=xa[j]&&ya[k]<=y[m]&&y[m]<=ya[l]){
							cnt++;
							}
						}
					if(cnt>=K){
						res=min(res,(ya[l]-ya[k])*(xa[j]-xa[i]));
						}	
					}
				}
			}
		}
		cout<<res<<endl;
	}
