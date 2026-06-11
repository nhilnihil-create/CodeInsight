//订正中 
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		string t=s;
		t.erase(i,s.size()-7);
		if(t=="keyence"){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}