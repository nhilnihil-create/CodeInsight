#include<iostream>
using namespace std;
long k,a;
string s;
int main(){
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]=='A')k++;
		else if(s[i]=='B'&&s[i+1]=='C')a+=k,i++;
		else k=0;
	}
	cout<<a;
	return 0;
}
