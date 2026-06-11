#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
	ll h,w,mod=pow(10,9)+7,n;
	cin>>n;
	vector<long double> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<vector<long double>> p(n+1,vector<long double>(n+1,(long double)0));
	p[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(!j)
			p[i][j]=p[i-1][j]*(1-a[i-1]);
			else {
				p[i][j]=p[i-1][j-1]*a[i-1]+p[i-1][j]*(1-a[i-1]);
			}
//			cout<<p[i][j]<<" ";
		}
//		cout<<endl;
	}
	if(n%2)
	cout<<setprecision(20)<<accumulate(p[n].begin()+ceil(n/2.0),p[n].end(),(long double)0)<<endl;
	else 
	cout<<setprecision(20)<<accumulate(p[n].begin()+n/2+1,p[n].end(),(long double)0)<<endl;
}
