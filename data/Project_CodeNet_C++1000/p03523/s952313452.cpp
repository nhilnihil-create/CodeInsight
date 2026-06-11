#include <bits/stdc++.h>
#define mem(s,t) memset(s,t,sizeof(s))
#define pb(s) push_back(s)
#define inf 0x3f3f3f3f
#define mn 100010
typedef long long ll;
using namespace std;
char s[100];
int main()
{
	scanf("%s",s);
	int p=0;
	int l=strlen(s);
	bool ok=1;
	for(int i=0;i<l&&ok;++i){
		if(s[i]!='A'&&(p==0||p==4||p==6||p==8))++p;
		switch(s[i]){
			case 'A':
				if(p==0||p==4||p==6||p==8)++p;
				else ok=0;
				break;
			case 'K':
				if(p==1)++p;
				else ok=0;
				break;
			case 'I':
				if(p==2)++p;
				else ok=0;
				break;
			case 'H':
				if(p==3)++p;
				else ok=0;
				break;
			case 'B':
				if(p==5)++p;
				else ok=0;
				break;
			case 'R':
				if(p==7)++p;
				else ok=0;
				break;
			default:
				ok=0;
		}
	}
	if(p<8)ok=0;
	if(ok)printf("YES\n");
	else printf("NO\n");

    return 0;
}
//AKIHABARA