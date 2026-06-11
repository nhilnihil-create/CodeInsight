#include<bits/stdc++.h>
using namespace std;
#define int 	long long int

int32_t main(){
	
	string str;
	cin>>str;

	int ans=0;
	for(int i=0;str[i];i++){
		if(str[i]=='-'){
			ans--;
		}
		else
			ans++;
	}
	cout<<ans<<endl;

	return 0;
}


