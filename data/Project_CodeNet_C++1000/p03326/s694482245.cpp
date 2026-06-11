#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<long long int>x(n),y(n),z(n),w(n);
	rep(i,n)cin>>x[i]>>y[i]>>z[i];
	long long int sum,max = -1;

	rep(i,8){
		if((i&1)==0){
			rep(j,n)w[j]=x[j];
		}else{
			rep(j,n)w[j]=-x[j];
		}
		if((i&2)==0){
			rep(j,n)w[j]+=y[j];
		}else{
			rep(j,n)w[j]-=y[j];
		}
		if((i&4)==0){
			rep(j,n)w[j]+=z[j];
		}else{
			rep(j,n)w[j]-=z[j];
		}
		sort(w.begin(),w.end());
		//rep(j,n)cout<<w[j]<<" ";
		//cout<<endl;
		sum=0;
		rep(j,m){
			sum+=w[n-j-1];
		}
		if(max<sum)max=sum;
	}
	cout<<max<<endl;



	return 0;
}
