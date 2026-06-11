#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
int t1,t2;
int BS(int s,int e){
	if(s==e)return s;
	int m=(s+e)/2+1;
	for(int i=m/2-1;i<=m/2+1;i++){
		if(i<=0||i>m)continue;
		if((ll)(t1+i)*(t1+m-i)>=(ll)t1*t2)return BS(s,m-1);
	}
	return BS(m,e);
}
int main(){
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&t1,&t2);
		if(t1>t2)swap(t1,t2);
		printf("%lld\n",(ll)2*(t1-1)+BS(0,t2-t1));
	}
}