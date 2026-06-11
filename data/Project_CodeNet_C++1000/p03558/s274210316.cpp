#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int mod,l,r,vis[100050];
struct node{
	long long tot,val;
}q[100050];
int main(){
	cin>>mod;
	q[l=r=1].tot=1;q[1].val=1;
	while(l<=r){
		
		if(!q[l].tot){
			cout<<q[l].val;return 0;
		}if(vis[q[l].tot]){
			++l;
		}else{
			vis[q[l].tot]=1;
			q[l].tot=q[l].tot*10%mod;q[l].val=q[l].val;
			q[++r].tot=(q[l].tot+1)%mod;q[r].val=q[l].val+1;
		}
	}
}