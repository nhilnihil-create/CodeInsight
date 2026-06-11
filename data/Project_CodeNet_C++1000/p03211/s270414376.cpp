#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	string s;
	cin>>s;
	int x=0;
	int y=753;
	int ans=100000000;
	int n=s.size();
	for(int i=0;i<n-2;i++){
	
		int z=100;
		x=0;
		for(int j=i;j<i+3;j++){
		
			x+=(int(s[j])-48)*z;
			z/=10;
		}
		if(abs(y-x)<ans){
		
			ans=abs(y-x);
		}

	}
	cout<<ans<<'\n';
	return 0;
}
