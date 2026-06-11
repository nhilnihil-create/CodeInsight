#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
	string s;
	cin>>s;
	if((s[6]=='1'||s[6]=='2'||s[6]=='3'||s[6]=='4')&&s[5]=='0'){
		cout<<"Heisei"<<endl;
	}
	else{
		cout<<"TBD"<<endl;
	}
	return 0;
}