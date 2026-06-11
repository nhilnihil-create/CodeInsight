#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	string s;
	cin>>s>>n;
	int f=0,i=0,ans;
	while (f==0){
		if (s[i]!='1'||n==1){
			ans=s[i]-'0';
			break;
		}
		n--;
		i++;
	}
	cout<<ans;
	return 0;
}