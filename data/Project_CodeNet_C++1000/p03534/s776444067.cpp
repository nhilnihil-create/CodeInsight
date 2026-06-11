#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
char c[1000000];
int a[3];
for(int i=0;i<3;i++)a[i]=0;
for(int i=0;i<1000000;i++)c[i]='\0';
scanf("%s",c);
for(int i=0;c[i]!='\0';i++)a[c[i]-'a']++;
sort(a,a+3);
if(a[2]-a[0]<=1)printf("YES\n");
else printf("NO\n");
}