#include <iostream>

using namespace std;

int main(){

	int n,d,x;
	int a;
	int ans=0;
	cin>>n>>d>>x;

	for(int i=0;i<n;i++){
	
		cin>>a;
		int j=0;
		int y=1;
		while(y<=d){
		
			j++;
			y=j*a+1;
		}
		ans+=j;
	}

	cout<<ans+x<<'\n';
	return 0;

}
