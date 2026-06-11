#include <iostream>

using namespace std;

int main(){

	int n,m,c;
	cin>>n>>m>>c;
	int b[m];
	int a[n][m];
	long long int temp=0;
	int ans=0;

	for(int i=0;i<m;i++){
	
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
	
		for(int j=0;j<m;j++){
		
			cin>>a[i][j];
			temp+=a[i][j]*b[j];
		}
		temp+=c;
		if(temp>0){

			ans++;
		}
		temp=0;
	}
	cout<<ans<<"\n";
	return 0;

}
