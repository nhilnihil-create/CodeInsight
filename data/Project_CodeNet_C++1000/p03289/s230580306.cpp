#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s[0]!='A'){
		cout<<"WA"<<endl;
		return(0);
	}
	int c=0;
	int b=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='C' && i!=1 && i!=s.size()-1){
			c++;
		}
		if(s[i]<'a')
			b++;
	}
	if(c!=1){
		cout<<"WA"<<endl;
		return(0);
	}
	if(b!=2){
		cout<<"WA"<<endl;
		return(0);
	}
	cout<<"AC"<<endl;
	return(0);
}