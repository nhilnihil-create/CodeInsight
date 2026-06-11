#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout<<#a<<":"<<a<<endl;
const ll INF=0x3f3f3f3f;
const ll N=1e6+7;
const ll mod=1e9+7;
ll maxn,minn;
ll T,n,m;
ll dp[N];
ll w[N];
ll v[N];

ll arr[N],ans[N]; //对应原数组和树状数组

ll lowbit(ll x){
    return x&(-x);
}

void update(ll i,ll k){    //在i位置加上k
    while(i<=n){
        ans[i]=max(ans[i],k);
        i=i+lowbit(i);
    }
}

ll query(ll i){        //求arr[1 - i]的和
    ll res = 0;
    while(i>0){
        res=max(res,ans[i]);
        i =i-lowbit(i);
    }
    return res;
}

int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		scanf("%lld",w+i);
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",v+i);
	}
	for(ll i=1;i<=n;i++){
		dp[i]=v[i]+query(w[i]);
		maxn=max(maxn,dp[i]);
		update(w[i],dp[i]);
	}
	cout<<maxn<<endl;


	return 0;
}



