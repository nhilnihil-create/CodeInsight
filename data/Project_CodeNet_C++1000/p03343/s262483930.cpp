#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const ll INF=1000000010;
const ll MOD=1000000007;
const ll LINF=1000000000000000000;
//解を二分探索しXを決め打ち？
//X未満が存在しない世界でK以上の長さをQ回以上取れるか？
int n,k,qu;
ll a[2010];
bool check(ll s){
	for(int i=0;i<n;i++){
		ll x=a[i];
		vector<ll> v,vv;
		for(int j=0;j<n;j++){
			if(a[j]<x){
				if(v.size()==0)continue;
				sort(all(v));
				for(int l=0;l<(int)v.size()-k+1;l++){
					vv.push_back(v[l]);
				}
				v.clear();
			}else{
				v.push_back(a[j]);
			}
		}
		sort(all(v));
		for(int l=0;l<(int)v.size()-k+1;l++){
			vv.push_back(v[l]);
		}
		if(vv.size()<qu)continue;
		sort(all(vv));
		if(vv[qu-1]<=x+s){
			return true;
		}
	}
	return false;
}
int main(){
	cin>>n>>k>>qu;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ok=INF,ng=-1;
	while(ok-ng>1){
		int mid=(ok+ng)/2;
		if(check(mid)){
			ok=mid;
		}else{
			ng=mid;
		}
	}
	cout<<ok<<endl;
}