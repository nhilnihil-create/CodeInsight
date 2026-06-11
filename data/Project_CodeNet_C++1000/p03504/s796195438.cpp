#include <bits/stdc++.h>
using namespace std;

int n,c;
int s[200001][31];

int main(){
	cin>>n>>c;
	int t1,t2,t3;
	for(int i=1; i<200001;i++){
		for(int j=1;j<=30;j++){
			s[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>t1>>t2>>t3;
		for(int j=t1*2-1;j<t2*2;j++){
			s[j][t3]=1;
		}
	}
	int ans=0;
	for(int i=1;i<200001;i++){
		int tmp=0;
		for(int j=1;j<=30;j++){
			tmp+=s[i][j];
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
}