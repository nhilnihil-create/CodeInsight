#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second

ll N,C;
ll D[35][35];
ll c[505][505];
ll X1[35],X2[35],X3[35];
ll ans=mod;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>C;

rep(i,C){
	rep(j,C){
		cin>>D[i][j];
	}
}

rep(i,N){
	rep(j,N){
		cin>>c[i][j];
		c[i][j]--;
	}
}

rep(k,C){
rep(i,N){
	rep(j,N){
		if((i+j)%3==0){
			X1[k]+=D[c[i][j]][k];
		}
		else if((i+j)%3==1){
			X2[k]+=D[c[i][j]][k];
		}
		else if((i+j)%3==2){
			X3[k]+=D[c[i][j]][k];
		}

	}
}
}

rep(i,C){
	rep(j,C){
		rep(k,C){
			if(i!=j&&j!=k&&i!=k){
				ans=min(ans,X1[i]+X2[j]+X3[k]);
			}
		}
	}
}

cout<<ans<<endl;

}
	
