 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
LL N;
LL X;
LL x[200011];
LL s[200011];
LL t[200011];
int main(){
	cin>>N>>X;
	REP(i,N){
		cin>>x[i];
	}
	s[0]=0;
	REP(i,N){
		s[i+1]=s[i]+x[i];
	}
	
	t[0]=5;
	t[1]=5;
	for(int i=2;i<N+1;i++){
		t[i]=t[i-1]+2;
	}
	
	LL ans=1e17;
	REP(i,N){
		LL y=i+1;
		LL c=0;
		LL now=0;
		for(int j=N;j>0;j-=y){
			LL aa=max(j-y,LL(0));
			now+=(t[c]*(s[j]-s[aa]));
			//cout<<"miii"<<now<<endl;
			c++;
			if(now>ans)break;
		}
		if(now>ans)continue;
		now+=X*(y+N);
		//cout<<now<<" aaa"<<endl;
		ans=min(ans,now);
	}
	cout<<ans<<endl;
    return 0;
}