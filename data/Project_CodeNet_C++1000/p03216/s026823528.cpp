#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e6;
string S;
int N;
int Q;
int cpsm[MAX_N+1],mpsm[MAX_N+1];
int main(){
	cin>>N>>S>>Q;
	REP(i,N){
		cpsm[i+1]=cpsm[i]+(S[i]=='C');
		mpsm[i+1]=mpsm[i]+(S[i]=='M');
	}
	REP(q,Q){
		int k;
		cin>>k;
		ll mccnt=0;
		ll ans=0;
		int lb=0,ub=0;
		while(lb<N){
			while(lb<N && S[lb]!='D'){
				if (S[lb]=='M'){
					mccnt-=cpsm[ub]-cpsm[lb];
				}
				lb++;
			}
			if(lb==N)break;
			if(ub<lb){
				ub=lb;
				mccnt=0;
			}
			while(ub<N && ub-lb<k){
				if(S[ub]=='C'){
					mccnt+=mpsm[ub]-mpsm[lb];
				}
				ub++;
			}
			ans+=mccnt;
			lb++;
		}
		cout<<ans<<endl;
	}
}