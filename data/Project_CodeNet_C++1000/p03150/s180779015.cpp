#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
string s;
cin>>s;
for(int i = 0; i < 7; i++){
	if(s.substr(0 , i) + s.substr(s.size() - 7 + i) == "keyence"){
		cout<<"YES"<<endl;
		return 0;
	}
}
cout<<"NO"<<endl;
return 0;
}