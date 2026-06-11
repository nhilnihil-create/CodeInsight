#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll xx[1005],yy[1005];

ll x[1005],y[1005];
ll u[1005],v[1005];

ll labs(ll v){
	if(v<0LL)return -v;
	return v;
}
string ans[1005];
vector<ll> vec;

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	bool flag=false;
	for(int i=0;i<n;i++){
		u[i]=x[i]+y[i];
		v[i]=x[i]-y[i];
		for(int j=i+1;j<n;j++){
			if((labs(x[i]-x[j])+labs(y[i]-y[j]))%2==1){
				flag=true;
			}
		}
	}
	if(flag){
		printf("-1\n");
		return 0;
	}
	vector<ll> res;
	for(int i=31;i>=1;i--){
		res.push_back(1LL<<i);
	}
	res.push_back(1);
	res.push_back(1);
	if((labs(x[0])+labs(y[0]))%2==1)res.push_back(1);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<n;j++){
			if(u[j]>=0 && v[j]>=0){
				ans[j]+='R';
				u[j]-=res[i];
				v[j]-=res[i];
			}else if(u[j]>=0 && v[j]<0){
				ans[j]+='U';
				u[j]-=res[i];
				v[j]+=res[i];
			}else if(u[j]<0 && v[j]>=0){
				ans[j]+='D';
				u[j]+=res[i];
				v[j]-=res[i];
			}else if(u[j]<0 && v[j]<0){
				ans[j]+='L';
				u[j]+=res[i];
				v[j]+=res[i];
			}
		}
	}
	printf("%d\n",(int)res.size());
	for(int i=0;i<res.size();i++){
		if(i>0)printf(" ");
		printf("%lld",res[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		cout << ans[i] << endl;
	}
	return 0;
} 