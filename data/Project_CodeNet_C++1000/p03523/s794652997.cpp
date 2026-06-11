	#include<stdio.h>
	#include<string.h>
	
	char aki[10]={"AKIHABARA"};
	
	int main(){
		char s[51];
		scanf("%s",s);
		int len=strlen(s);
		int x=0;
		int test=0;
		int count=0;
		int y=0;
		int found=0;
		int j=0;
		for(int i=0;i<len;i++){
			if(s[i]=='A'){
				count++;
			}else if(s[i]=='K'||s[i]=='I'||s[i]=='H'||s[i]=='B'||s[i]=='R') y++;
			if(count>4||y>5){
				test=1;
				break;
			}
			found=0;
			while(j<9){
				if(s[i]==aki[j]){
					found=1;
	//				if(j!=0&&aki[j-1]!='A'&&aki[j-1]!='0'){
	//					test=1;
	//					break;
	//				}else{
	//					aki[j]='0';
	//					break;
	//				}
					int temp=j-1;
					int ct=0;
					while(temp>=0){
						if(aki[temp]!='0'&&aki[temp]!='A'){
							test=1;
							break;
						}
						temp--;
					}
					if(test==1) break;
					else{
//						if(aki[j+1]=='0'){
//							test=1;
//							break;
//						}
						aki[j]='0';
						break;
					}
				}
				j++;
			}
			if(found==0){
				test=1;
				break;
			}
			if(test==1){
				break;
			}
		}
		if(y!=5) test=1;
//		printf("%s %d\n",aki,y);
		if(test==1) printf("NO\n");
		else printf("YES\n");
		return 0;
	}