#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
typedef long long ll;
int INF=1<<29;

int main(){
    ios::sync_with_stdio(false);
	double N,tmp=0,sum=0;
	cin>>N;
	vector<double> t(N),v(N);
	for(int i=0;i<N;i++){
		cin>>t[i];
		sum+=t[i];
		t[i]+=tmp;
		tmp=t[i];
	}
	for(int i=0;i<N;i++) cin>>v[i];
	vector<double> table(sum*2+1);

	//table初期化
	for(double i=1;i<=sum;i++) table[i]=(i-1)*1+0.5;
	for(double i=sum*2;i>=sum+1;i--) table[i]=(sum*2-i)*1+0.5;

	//本題
	for(int i=0;i<N;i++){
		if(i!=0){
			//基
			for(double j=t[i-1]*2+1;j<=t[i]*2;j++){
				table[j]=min(table[j],2*v[i]);
			}
			//左
			for(double j=t[i-1]*2;j>=1;j--){
				table[j]=min(table[j],2*v[i]+(t[i-1]*2-j)*1+0.5);
			}
			//右
			for(double j=t[i]*2+1;j<=table.size();j++){
				table[j]=min(table[j],2*v[i]+(j-(t[i]*2+1))*1+0.5);
			}
		}else if(i==0){
			for(double j=1;j<=t[i]*2;j++){
				table[j]=min(table[j],2*v[i]);
			}
			//右
			for(double j=t[i]*2+1;j<=table.size();j++){
				table[j]=min(table[j],2*v[i]+(j-(t[i]*2+1))*1+0.5);
			}
		}
	}

	double ans=0;
	for(int i=1;i<table.size();i++){
		ans+=table[i];
	}
	ans/=4;
	cout<<fixed<<ans;
}