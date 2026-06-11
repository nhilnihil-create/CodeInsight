#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f[100009],lef,rig,mid,g[100009],fen[200009],ans,pas,zx;
void upd(long long q){
	while(q<=200005){
		fen[q]++;
		q=q+(q&(-q));
	}
}
void upd2(long long q){
	while(q<=200005){
		fen[q]--;
		q=q+(q&(-q));
	}
}
long long read(long long q){
	if(q<=0) return 0;
	long long jm=0;
	while(q>=1){
		jm+=fen[q];
		q=q-(q&(-q));
	}
	return jm;
}
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a;
	for(b=1; b<=a; b++){
		cin>>f[b];
	}
	if((a+1)*a/2/2%2==1) zx=(a+1)*a/2/2; else zx=(a+1)*a/2/2+1;
//	cout<<zx<<endl;
	lef=0;rig=1000000001;
	while(1){
		if(lef+1>=rig) break;
		mid=(lef+rig)/2;
//		cout<<mid<<endl;
		g[0]=0;
		for(b=1; b<=a; b++){
			g[b]=g[b-1];
			if(f[b]<mid) g[b]--; else g[b]++;
		}
		pas=0;
		for(b=a; b>=1; b--){
		    upd(g[b]+100001);
			pas+=a-b+1-read(g[b-1]-1+100001);
			//if(mid<=30) cout<<mid<<" "<<pas<<endl;
		}
		for(b=a; b>=1; b--){
		    upd2(g[b]+100001);
		}
		if(pas<zx){
			rig=mid;
		}else{
			ans=mid;
			lef=mid;
		}
	}
	cout<<ans;
	return 0;
}