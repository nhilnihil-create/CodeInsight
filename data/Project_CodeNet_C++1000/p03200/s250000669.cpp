#include <iostream>
#include <string>

using namespace std;

int main(){

	string s;
	cin>>s;
	int n=s.size();
	int x=n-1;
	long long int ans=0;
	for(int i=n-1;i>-1;i--){
		if(s[i]=='B'){
			ans+=x-i;
			x--;
		}
	}
	cout<<ans<<'\n';
}
