#include <iostream>
#include <string>

using namespace std;

int main(){

	string s;
	cin>>s;
	int n=s.size();
	int ans=0;
	int temp=0;

	for(int i=0;i<n;i++){

		if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T'){
		
			temp++;
		}

		else{
		
			if(temp>ans){
			
				ans=temp;
			}
			temp=0;
		}
		if(temp>ans){
		
			ans=temp;
		}
	}

	cout<<ans<<'\n';
	return 0;
}
