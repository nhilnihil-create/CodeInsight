#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll f[55][55];
int main(){
	ll n,c;
	cin>>n>>c;
	vector<ll>x(n),y(n),xx(n),yy(n),nx(n),ny(n);
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	xx=x;
	yy=y;
	sort(xx.begin(),xx.end());
	sort(yy.begin(),yy.end());
	xx.erase(unique(xx.begin(),xx.end()),xx.end());
	yy.erase(unique(yy.begin(),yy.end()),yy.end());
	for(int i=0;i<n;i++){
		auto p=lower_bound(xx.begin(),xx.end(),x[i]);
		auto q=lower_bound(yy.begin(),yy.end(),y[i]);
		nx[i]=p-xx.begin()+1;
		ny[i]=q-yy.begin()+1;
	}
	for(int i=0;i<n;i++)f[nx[i]][ny[i]]=1;
	sort(nx.begin(),nx.end());
	sort(ny.begin(),ny.end());
	nx.erase(unique(nx.begin(),nx.end()),nx.end());
	ny.erase(unique(ny.begin(),ny.end()),ny.end());
	ll ans=5e18;
	// for(int i=0;i<nx.size();i++)cout<<nx[i]<<' ';
	// cout<<endl;
	// for(int i=0;i<nx.size();i++)cout<<xx[i]<<' ';
	// cout<<endl;
	// for(int i=0;i<ny.size();i++)cout<<ny[i]<<' ';
	// cout<<endl;
	// for(int i=0;i<ny.size();i++)cout<<yy[i]<<' ';
	// cout<<endl;
	for(int i=0;i<=50;i++)for(int j=1;j<=50;j++)f[i][j]+=f[i][j-1];
	for(int i=0;i<=50;i++)for(int j=1;j<=50;j++)f[i][j]+=f[i-1][j];
	for(int i=0;i<nx.size();i++){
		for(int j=0;j<ny.size();j++){
			for(int k=i+1;k<nx.size();k++){
				for(int l=j+1;l<ny.size();l++){
					if(f[nx[k]][ny[l]]+f[nx[i]-1][ny[j]-1]-f[nx[k]][ny[j]-1]-f[nx[i]-1][ny[l]]>=c){
						ans=min(ans,(xx[k]-xx[i])*(yy[l]-yy[j]));
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
