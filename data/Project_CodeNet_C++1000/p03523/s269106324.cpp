#include<bits/stdc++.h>
using namespace std;
char s[150],key[150]="AKIHABARA";
int cek;
int main(){
	//printf("a");
	scanf("%s",s);
	int c=strlen(key);
	int d=strlen(s);
	int cur=0;
	cek=1;
	if(d>c){
		cek=0;
	}else{
		for(int i=0;i<c;i++,cur++){
			if(cur==d){
				cur--;
			}
		//	printf("%c %c\n",key[i],s[cur]);
			if(key[i]!=s[cur]&&key[i]=='A'&&i==c-1){
				if(key[i-1]!=s[cur]){
					cek=0;
					break;
				}
				i++;
			}else if(key[i]!=s[cur]&&key[i]=='A'){
			//	puts("1");
				if(key[i+1]!=s[cur]){
					cek=0;
					break;
				}
				i++;
			}else if(key[i]!=s[cur]&&key[i]!='A'){
				cek=0;
				break;
			}
		}
	}
	if(cek==0){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
return 0;
}
