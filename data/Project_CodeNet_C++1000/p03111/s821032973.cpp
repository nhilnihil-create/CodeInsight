#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N,A,B,C;
ll l[10];
ll bit[10];
ll ans=INF;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>A>>B>>C;
rep(i,N) cin>>l[i];
rep(i1,4){
	rep(i2,4){
		rep(i3,4){
			rep(i4,4){
				rep(i5,4){
					rep(i6,4){
						rep(i7,4){
							rep(i8,4){
								bit[0]=i1;
								bit[1]=i2;
								bit[2]=i3;
								bit[3]=i4;
								bit[4]=i5;
								bit[5]=i6;
								bit[6]=i7;
								bit[7]=i8;
								ll a=0; ll acost=0;
								ll b=0; ll bcost=0;
								ll c=0; ll ccost=0;
								rep(k,N){
									if(bit[k]==0){
										a+=l[k];
										acost++;
									}
									if(bit[k]==1){
										b+=l[k];
										bcost++;
									}
									if(bit[k]==2){
										c+=l[k];
										ccost++;
									}
								}
								if(acost==0||bcost==0||ccost==0) continue;
								ll cost=0;
								cost+=abs(A-a);
								cost+=abs(B-b);
								cost+=abs(C-c);
								cost+=10*(acost-1);
								cost+=10*(bcost-1);
								cost+=10*(ccost-1);
								ans=min(ans,cost);
							}
						}
					}
				}
			}
		}
	}
}
cout<<ans<<endl;

}
    
