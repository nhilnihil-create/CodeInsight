#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
	//~ double Min=LLONG_MAX;
	//~ vector<int>v;
	//~ for(int i=111111111;i>=1;i--){
		//~ int a=i,c=0;
		//~ while(a)c+=a%10,a/=10;
		//~ double d=i/(double)c;
		//~ if(i<=100000000){
			//~ if(d<=Min)v.push_back(i);
		//~ }
		//~ Min=min(Min,d);
	//~ }
	//~ reverse(v.begin(),v.end());
	//~ for(int i:v){
		//~ cout<<i<<endl;
	//~ }
	vector<ll>v;
	for(int i=1;i<=99;i++)v.push_back(i);
	for(int i=3;i<=16;i++){//桁数
		for(int j=100;j<=999;j++){
			ll d=j+1;rep(k,i-3)d*=10;d--;
			v.push_back(d);
		}
	}
	vector<ll>ans;
	double Min=LLONG_MAX;
	for(int i=v.size()-1;i>=0;i--){
		ll a=v[i],c=0;
		while(a)c+=a%10,a/=10;
		double d=v[i]/(double)c;
		if(d<=Min){
			ans.push_back(v[i]);
		}
		Min=min(Min,d);
	}
	reverse(ans.begin(),ans.end());
	int k;scanf("%d",&k);
	rep(i,k){
		cout<<ans[i]<<endl;
	}
}