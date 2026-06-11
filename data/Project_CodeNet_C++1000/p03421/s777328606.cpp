#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N,A,B;
int C[300001];
void swa(int x,int y){
	//cout<<x<<y<<endl;
	/*REP(i,N){
		cout<<C[i];
		if(i==N-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}*/
	while(x<y){
		int D=C[x];
		C[x]=C[y];
		C[y]=D;
		x++;
		y--;
	}
	/*REP(i,N){
		cout<<C[i];
		if(i==N-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}*/
}
int Cnt[300001];

int main(){
	REP(i,300001){
		Cnt[i]=0;
	}
	cin>>N>>A>>B;
	if(A+B>N+1){
		cout<<-1<<endl;
		return 0;
	}
	if(A>N){
		cout<<-1<<endl;
		return 0;
	}
	if(B>N){
		cout<<-1<<endl;
		return 0;
	}
	if(A==1&&(B!=N)){
		cout<<-1<<endl;
		return 0;
	}
	if(B==1&&(A!=N)){
		cout<<-1<<endl;
		return 0;
	}

	
	REP(i,N){
		C[i]=i+1;
	}
	
	int res=N-A;
	int pos=0;
	while(res!=0){
		//cout<<pos<<" "<<pos+min(res+1,B)<<endl;
		swa(pos,pos+min(res+1,B)-1);
		res-=(min(res+1,B)-1);
		pos+=B;
	}
	int c=0;
	int now=0;
	REP(i,N){
		if(now<C[i]){
			c++;
			//cout<<now<<" "<<C[i]<<endl;
			now=C[i];
		}
		if(C[i]<=0||C[i]>N){
			cout<<-1<<endl;
			return 0;
		}
		Cnt[C[i]-1]++;
	}
	REP(i,N){
		if(Cnt[i]!=1){
			cout<<-1<<endl;
			return 0;
		}
	}
	//cout<<now<<" "<<A<<endl;
	if(A!=c){
		cout<<-1<<endl;
		return 0;
	}
	
	REP(i,N){
		cout<<C[i];
		if(i==N-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
	
	return(0);
}