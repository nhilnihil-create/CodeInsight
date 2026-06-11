#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int m=0,l;
char s[200005];
int main(){
    scanf("%s",s);
    l=strlen(s) ;
    if(s[0]=='0'){
    	puts("-1");
		return 0;
	}
    if(s[l-1]=='1'){
    	puts("-1");
		return 0;
	}
    for(int i=0;i<l-1;i++)
        if(s[i]!=s[l-i-2]){
    		puts("-1");
			return 0;
		}
    for(int i=0;i<l-1;i++){
        printf("%d %d\n",m+1,i+2);
        if(s[i]=='1')m=i+1;
    }
    return 0 ;
}