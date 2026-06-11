#include<bits/stdc++.h>
using namespace std;
int  t;
long long a;
char c;
char s[200010];
int main(){
	gets(s);
	bool flag=false;
	 for(int i=0;i<strlen(s);i++){
	 	int c=s[i];
	 	if(flag) {
	 		flag=false;
	 		continue;
	 	}
	 	if(c=='A') t++;
	 	if(c=='B') {
	 		if(i+1<strlen(s)){
	 			c=s[i+1];
	 			flag=true;
	 		}
	 		else c='\n';
	 		if(c=='C'){
	 			a+=t;
	 			continue;
	 		}
	 		else{
				if(c=='A') t=1;
				else t=0;
			}
		}
		if(c=='C') t=0;
	}
	printf("%lld",a);
	return 0;
}