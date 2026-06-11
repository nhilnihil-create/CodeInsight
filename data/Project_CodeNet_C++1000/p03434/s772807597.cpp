#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	int ch=0;
	for(int i=n-1;i>-1;i--){

		if(ch==0){
		
			ans+=a[i];
			ch=1;
		}
		else{
		
			ans-=a[i];
			ch=0;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
