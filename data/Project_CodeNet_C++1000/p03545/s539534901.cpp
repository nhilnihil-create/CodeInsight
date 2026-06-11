#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	int ans;
	cin>>s;
	for(int i=0;i<8;i++){
		ans=s[0]-'0';
		for(int j=0;j<3;j++){
			if(i&(1<<j))
				ans+=s[j+1]-'0';
			else
				ans-=s[j+1]-'0';
		}
		if(ans==7){
			cout<<s[0];
			for(int j=0;j<3;j++){
				if(i&(1<<j))
					cout<<"+"<<s[j+1];
				else
					cout<<"-"<<s[j+1];
			}
			cout<<"=7";
			return 0;	
		}
	}
}
