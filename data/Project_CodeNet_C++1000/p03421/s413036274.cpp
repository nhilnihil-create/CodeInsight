#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
	int n,a,b;cin>>n>>a>>b;
	if(a+b-1>n||a*(ll)b<n){
		puts("-1");return 0;
	}
	vector<int>ans;
	rep(i,b){
		int d=1;
		if(a>1){
			if(i<(n-b)/(a-1))d=a;
			if(i==(n-b)/(a-1))d=1+(n-b)%(a-1);
		}
		int c=n-ans.size()-d+1;
		rep(j,d)ans.push_back(c+j);
	}
	rep(i,ans.size()){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	puts("");
}