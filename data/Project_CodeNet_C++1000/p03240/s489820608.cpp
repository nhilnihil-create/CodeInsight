#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x[n],y[n],h[n];
	for (int i=0;i<n;i++){
		cin>>x[i]>>y[i]>>h[i];
	}
	int ans[3]={0};
	for (int i=0;i<=100;i++){
		for (int j=0;j<=100;j++){
			int H,flag=0;
			for (int z=0;z<n;z++){
				if (h[z]==0){
					continue;
				}
				H=h[z]+abs(i-x[z])+abs(j-y[z]);
				break;
			}
			for (int z=0;z<n;z++){
				if(h[z]!=max(0,(H-abs(i-x[z])-abs(j-y[z])))) {
					flag=1;
				}
			}
			if (flag==0){
				ans[0]=i;
				ans[1]=j;
				ans[2]=H;
			}
		}
	}
	cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
	return 0;
}