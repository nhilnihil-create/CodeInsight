#include<bits/stdc++.h>
using namespace std;
int d;
long long a;
char s[200010];
int main(){
	gets(s);
	bool flag=false;//标记 为false 
	for(int i=0;i<strlen(s);i++){
	 	if(flag) {//如果这个被处理过了，跳过循环 
	 		flag=false;
	 		continue;
	 	}
	 	if(s[i]=='A') d++;//标记A 
	 	if(s[i]=='B') {//标记B 
	 		if(i+1<strlen(s))//将下一个标记掉 
	 			flag=true;
	 		if(s[i+1]=='C'){
	 			a+=d;//相加 
	 			continue;//跳过循环 
	 		}
	 		else{
				if(s[i+1]=='A') d=1;
				else d=0;//清零 
			}
		}
		if(s[i]=='C') d=0;
	}
	printf("%lld",a);//输出 
	return 0;
}