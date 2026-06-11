#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n%2==0){
		cout<<n*(n-1)/2-n/2<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i+j==n+1){
					continue;
				}else{
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}else{
		cout<<n*(n-1)/2-(n-1)/2<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i+j==n){
					continue;
				}else{
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	return 0;
}