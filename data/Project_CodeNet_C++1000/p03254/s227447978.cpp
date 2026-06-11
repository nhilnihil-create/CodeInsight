#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int n,am;
	cin>>n>>am;
	int a[n];
	int ans=0;

	for(int i=0;i<n;i++){
	
		cin>>a[i];
	}
	sort(a,a+n);

	for(int i=0;i<n;i++){
	
		am-=a[i];
		ans++;
		if(am==0){
		
			break;
		}
		if(am<0){
		
			ans--;
			break;
		}
	}
	if(am>0){
	
		ans--;
	}
	cout<<ans<<'\n';
	return 0;
}
