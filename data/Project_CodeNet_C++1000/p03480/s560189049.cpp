#include<iostream>
#include<cstring>
using namespace std;
char s[100005];
int ans;
int main(){
	cin>>s;
	int len=strlen(s);
	ans=len;
	for(int i=0;i<len;i++){
		if(s[i]!=s[i-1]){
			ans=min(ans,max(i,len-i));
		}
	}
	cout<<ans;
} 