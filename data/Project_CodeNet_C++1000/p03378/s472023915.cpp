#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int n,m,x;
	cin>>n>>m>>x;

	int a[m];
	int s,b;
	int ans1=0;
	int ans2=0;
	for(int i=0;i<m;i++){
	
		cin>>a[i];
	}
	s=a[0];
	b=a[m-1];

	for(int i=x;i<n+1;i++){

		if(i<=b){
		
			for(int j=m-1;j>-1;j--){

				if(a[j]==i){
				
					ans1++;
					break;
				}
			}
		}
	}
	for(int i=x;i>-1;i--){
	
		if(i>=s){
		
			for(int j=0;j<m;j++){
			
				if(a[j]==i){
				
					ans2++;
					break;
				}
			}
		}
	}

	cout<<min(ans1,ans2)<<'\n';
	return 0;
}
