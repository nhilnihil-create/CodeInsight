#include<bits/stdc++.h>
using namespace std;
int n,m;
double ans;
int main(){
	int x=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int k=max(0.0,ceil(log2(1.0*m/i)));
		ans+=1.0/((1<<k)*n);
	}
	printf("%.10lf",ans);
}