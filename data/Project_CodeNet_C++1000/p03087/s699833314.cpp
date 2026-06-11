#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int sum[200000];
int main(){
	int n,q;string s;cin>>n>>q>>s;
	rep(i,s.size()-1){
		sum[i+1]+=sum[i];
		if(s[i]=='A'&&s[i+1]=='C')sum[i+1]++;
	}
	rep(i,q){
		int l,r;scanf("%d%d",&l,&r);l--;
		printf("%d\n",sum[r-1]-sum[l]);
	}
}