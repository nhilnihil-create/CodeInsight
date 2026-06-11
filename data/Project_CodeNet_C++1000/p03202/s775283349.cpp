 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
int N;
LL A[200001];
typedef pair<int,int>P;
P p[200001];

bool check(LL x){
	p[0]=P(1,A[0]);
	LL now=0;
	for(int i=1;i<N;i++){
		if(A[i]-A[i-1]>0){
			if(p[now].first==1){
				p[now].second=p[now].second+(A[i]-A[i-1]);
			}else{
				now++;
				p[now]=P(1,A[i]-A[i-1]);
			}
		}else{
			int B=A[i-1]-A[i];
			while(B!=0){
				if(p[now].second==B){
					B-=p[now].second;
					now--;
				}else if(p[now].second<B){
					B-=p[now].second;
					now--;
				}else{
					p[now].second-=B;
					B=0;
				}
			}
			LL AA=0;
			if(p[now].first==x){
				if(now==0)return false;
				AA=p[now].second;
				if((p[now-1].second==1)&&(now!=1)&&(p[now-1].first+1==p[now-2].first)){
					now-=2;
					p[now].second+=1;
				}else{
					if(p[now-1].second==1){
						now-=1;
						p[now].first=p[now].first+1;
					}else{
						now-=1;
						p[now].second-=1;
						now++;
						p[now]=P(p[now-1].first+1,1);
					}
				}
				
				now++;
				p[now]=P(1,AA);
			}else{
				if((p[now].second==1)&&(now!=0)&&(p[now].first+1==p[now-1].first)){
					now-=1;
					p[now].second+=1;
				}else{
					if(p[now].second==1){
						p[now].first=p[now].first+1;
					}else{
						p[now].second-=1;
						now++;
						p[now]=P(p[now-1].first+1,1);
					}
				}
			}
		}
	}
	return true;
}

int main(){
	cin>>N;
	REP(i,N){
		cin>>A[i];
	}
	LL lb=0;
	LL ub=1e9;
	while(ub-lb>1){
		LL mid=(ub+lb)/2;
		if(check(mid)){
			ub=mid;
		}else{
			lb=mid;
		}
	}
	cout<<ub<<endl;
	
    return 0;
}