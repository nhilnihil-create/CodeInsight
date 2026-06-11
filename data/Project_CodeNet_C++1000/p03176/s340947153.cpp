#include<bits/stdc++.h>

#define X first
#define Y second
#define ll long long
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN=2e5;

ll n;
ll vis[MAXN+5],lje[MAXN+5];
ll rj;
ll tur[(1<<19)];
ll dp[MAXN+5];
ll trn;

void update(ll cvor, ll a, ll b, ll x, ll y, ll vrj){
	
//		cout<<"\n 1 \n";
	if(b<x || a>y){
		return;
	}
	if(a>=x && b<=y){
		tur[cvor]=max(tur[cvor],vrj);
		return;
	}
	update(cvor*2,a,(a+b)/2,x,y,vrj);
	update(cvor*2+1,(a+b+1)/2,b,x,y,vrj);
}

ll nadi(ll x){
	trn=0;
	while(x>0){
		trn=max(trn,tur[x]);
		x/=2;
	}
	return trn;
}

int main () {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	//tur[1]=n;
	for(int i=0; i<n; i++){
		cin>>vis[i];
	}
	for(int i=0; i<n; i++){
		cin>>lje[i];
	//	cout<<"\n 1 \n";
		dp[i]=nadi(vis[i]+(1<<18)-1)+lje[i];
		rj=max(rj,dp[i]);
		update(1,1,(1<<18),vis[i],(1<<18),dp[i]);
	}
	cout<<rj<<"\n";
	
	return 0;
}