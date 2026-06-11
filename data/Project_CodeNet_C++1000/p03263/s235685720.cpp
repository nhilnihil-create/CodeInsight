#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[550][550];
int main(){
	ll h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)cin>>a[i][j];
	ll cnt=0;
	vector<pair<pair<ll,ll>,pair<ll,ll>>>v;
	for(int i=1;i<=h;i++){
		if(i%2){
			for(int j=1;j<=w;j++){
					if(i==1&&j==1)continue;
					if(j==1){
						if(a[i-1][j]%2){
							cnt++;
							a[i][j]++;
							v.push_back({{i-1,j},{i,j}});
						}
					}else{
						if(a[i][j-1]%2){
							cnt++;
							a[i][j]++;
							v.push_back({{i,j-1},{i,j}});
						}
					}
			}
		}else{
			for(int j=w;j>=1;j--){
					if(j==w){
						if(a[i-1][j]%2){
							cnt++;
							a[i][j]++;
							v.push_back({{i-1,j},{i,j}});
						}
					}else{
						if(a[i][j+1]%2){
							cnt++;
							a[i][j]++;
							v.push_back({{i,j+1},{i,j}});
						}
					}
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i].first.first<<' '<<v[i].first.second<<' '<<v[i].second.first<<' '<<v[i].second.second<<endl;
	}
	return 0;
}
