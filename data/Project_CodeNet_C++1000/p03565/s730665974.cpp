#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[10010],t[10010];
	scanf("%s%s",s,t);
	int ls=strlen(s),lt=strlen(t);
	for(int i=ls-lt;i>=0;i--){
		if(s[i]==t[0]||s[i]=='?'){
			bool flag=true;
			for(int j=0;j<lt;j++){
				if(t[j]!=s[j+i]&&s[j+i]!='?'){
					flag=false;
					break;
				}
			}
			if(flag==true){
				for(int j=0;j<lt;j++)s[j+i]=t[j];
				for(int j=0;j<ls;j++){
					if(s[j]=='?')cout<<'a';
					else cout<<s[j];
				}
				return 0;
			}
		}
	}
	cout<<"UNRESTORABLE";
	return 0;
} 