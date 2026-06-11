#include <bits/stdc++.h>
using namespace std;
string s,w="keyence";
 
int main(){
	cin>>s;
	string a,b;
	for(int i=0;i<w.size();i++){
		a=s.substr(0,i+1);
		b=s.substr(s.size()-(7-i-1));
		if(a+b==w){
			cout<<"YES";
			return 0;
		} 
	}

	cout<<"NO";
	return 0;
}
