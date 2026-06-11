#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 200005
char s[N]; 
int a[10];
bool ck=0;
int main() 
{
	int n;
	cin>>n;
	for(int i=1;i<=4;i++) scanf("%d",&a[i]);
	scanf("%s",s+1);
	int z=max(a[3],a[4]);
	int len=strlen(s+1);
	for(int i=a[1]+1;i<=a[3];i++)
	{
		if(s[i]=='#'&&s[i]==s[i-1]) 
		{
			printf("No\n");
			return 0;
		}
	}
	for(int i=a[2]+1;i<=a[4];i++)
	{
		if(s[i]=='#'&&s[i]==s[i-1]) 
		{
			printf("No\n");
			return 0;
		}
	}
	if(a[4]<a[3])
	{
	    for(int i=a[2];i<=a[4];i++)
		{
			
		    if(s[i]=='.'&&s[i-1]=='.'&&s[i+1]=='.')
			{
					printf("Yes\n");
			return 0;
				}	
		}	
			printf("No\n");
			return 0;
	}
	printf("Yes\n");
	return 0;
}