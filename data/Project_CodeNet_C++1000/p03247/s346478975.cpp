#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1000;
int N;
ll U[MAX_N],V[MAX_N];
bool uflg[35],vflg[35];
const int M=35;
int main(){
	cin>>N;
	REP(i,N){
		ll x,y;
		cin>>x>>y;
		U[i]=x+y;
		V[i]=y-x;
	}
	bool flg=true;
	int p=(U[0]&1);
	REP(i,N){
		if (p!=(U[i]&1) || p!=(V[i]&1)){
			flg=false;
		}
	}
	if (flg){
		cout<<(p==1 ? M+1 : M)<<endl;
		REP(i,M){
			ll x;
			if (i){
				cout<<" ";
			}
			if (i<=1){
				x=1;
			}else{
				x=(1ll<<(i-1));
			}
			cout<<x;
		}
		if (p==1){
			cout<<" 1";
		}
		cout<<endl;
		if (p==1){
			REP(i,N){
				U[i]--;
				V[i]++;
			}
		}
		REP(i,N){
			ll cur=0;
			for(int j=M-1;j>=0;j--){
				ll x;
				if (j<=1){
					x=1;
				}else{
					x=(1ll<<(j-1));
				}
				if (cur<=U[i]){
					uflg[j]=true;
					cur+=x;
				}else{
					uflg[j]=false;
					cur-=x;
				}
			}
			cur=0;
			for(int j=M-1;j>=0;j--){
				ll x;
				if (j<=1){
					x=1;
				}else{
					x=(1ll<<(j-1));
				}
				if (cur<=V[i]){
					vflg[j]=true;
					cur+=x;
				}else{
					vflg[j]=false;
					cur-=x;
				}
			}
			REP(i,M){
				char c;
				if (uflg[i]){
					if (vflg[i]){
						c='U';
					}else{
						c='R';
					}
				}else{
					if (vflg[i]){
						c='L';
					}else{
						c='D';
					}
				}
				cout<<c;
			}
			if (p==1){
				cout<<'R';
			}
			cout<<endl;
		}
	}else{
		cout<<-1<<endl;
	}
	return 0;
}