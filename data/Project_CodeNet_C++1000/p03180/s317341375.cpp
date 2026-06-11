#include <iostream>
#include <vector>
using namespace std;
const long long int inf =-1e18;
vector<long long int>dp;
vector<long long int>pre;

void f(int mask,const vector<int>&nt,int i,long long int tempans,int group){
    if(i==nt.size()){
        dp[mask]=max(dp[mask],tempans+pre[group]);
        return;
    }
    f(mask,nt,i+1,tempans,group);
    f(mask^(1<<nt[i]),nt,i+1,tempans,group^(1<<nt[i]));
    return;
}

int main() {
	int n;
	scanf("%d",&n);
	dp=vector<long long int>(1<<n,inf);
	vector<vector<int>>matrix(n,vector<int>(n));
	for(int i=0;i<n;i+=1){
	    for(int j=0;j<n;j+=1){
	        scanf("%d",&matrix[i][j]);
	    }
	}
	pre.resize(1<<n);
	for(int m=0;m<(1<<n);m+=1){
	    for(int i=0;i<n;i+=1){
	        if(m&(1<<i)){
	            for(int j=i+1;j<n;j+=1){
	                if(m&(1<<j)){
	                    pre[m]+=matrix[i][j];
	                }
	            }
	        }
	    }
	}
	dp[0]=0;
	for(int m=0;m<(1<<n);m+=1){
	    vector<int>nt;
	    for(int i=0;i<n;i+=1){
	        if(!(m&(1<<i))){
	            nt.push_back(i);
	        }
	    }
	    f(m,nt,0,dp[m],0);
	}
	printf("%lld",dp[(1<<n)-1]);
	return 0;
}
