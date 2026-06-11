#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll mod=1e9+7;
ll inf=1e18;

/*
AC
*/

struct d{
	ll a,b,c;
};

int main(void){
	ll n,r,sum=0;
	vector<d> ans;
	cin>>n;
	irep(i,20){
		if(n-1 >= (1<<i)-1){
			r = i+1;//r=点の数
			n -= 1<<i;
			sum += 1<<i;
			break;
		}
	}
	while(n>0){
		irep(i,20){
			if(n-1 >= (1<<i)-1){
				ans.push_back({r-2,i-1,sum});
				n -= 1<<i;
				sum += 1<<i;
				break;
			}
		}
	}
	reg(i,-1,r-2){
		if(i!=-1){
			ans.push_back({i,i-1,1<<i});
			ans.push_back({i,i-1,0});
		}
	}
	rep(i,ans.size()){
		ans[i].a=r-ans[i].a-1;
		ans[i].b=r-ans[i].b-1;
	}
	printf("%lld %lu\n",r,ans.size());
	rep(i,ans.size()){
		printf("%lld %lld %lld\n",ans[i].a,ans[i].b,ans[i].c);
	}
	return 0;
}