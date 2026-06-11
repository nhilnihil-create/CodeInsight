#include <iostream>
#include <climits>
using namespace std;

int main(){
	int n,temp;
	cin>>n;
	int f[n],c[n][11];
	for(int i=0;i<n;i++){
		f[i]=0;
		for(int j=0;j<10;j++){
			cin>>temp;
			if(temp) f[i]|=(1<<j);
		}
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<11;j++)
			cin>>c[i][j];
	
	int maxProfit=INT_MIN;
	for(int i=(1<<10)-1;i>0;i--){
		int profit=0;
		for(int j=0;j<n;j++){
			profit+=c[j][__builtin_popcount(f[j]&i)];
		}
		maxProfit=max(maxProfit,profit);
	}
  	cout<<maxProfit<<endl;
}