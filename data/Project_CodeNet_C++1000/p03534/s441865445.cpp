#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int chk[5];
char s[100005];
int main(){
    int n,i;
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;i++)    chk[s[i]-'a']++;
    sort(chk,chk+3);
    if(chk[2]-1>chk[0]){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
}
