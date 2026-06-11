#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,int> PPIII;
typedef vector<PPIII> VPPIII;
VPPIII es;
void ae(int u,int v,int w){
	es.push_back(PPIII(PII(u,v),w));
}
int n=1;
void print(){
	printf("%d %d\n",n,(int)es.size());
	// sort(es.begin(),es.end());
	for(VPPIII::iterator it=es.begin();it!=es.end();++it){
		printf("%d %d %d\n",it->first.first,it->first.second,it->second);		
	}
}
int main(){
	int l;
	scanf("%d",&l);
	for(n=0;(2<<n)<=l;){
		n++;
		ae(n,n+1,1<<(n-1));
		ae(n,n+1,0);
	}
	int c=1<<n;
	for(int i=n-1;i>=0;i--){
		if((1<<i)&l){
			ae(i+1,n+1,c);
			c+=1<<i;
		}
	}
	n++;
	print();
}