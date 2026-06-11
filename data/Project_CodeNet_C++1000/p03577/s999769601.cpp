#include<cstdio>
int len(char *s){
    int i=0;
    while(s[i]!='\0')i++;
    return i;
}
int main(){
    char s[51];
    scanf("%s",s);
    for(int i=0;i<len(s)-8;i++)printf("%c",s[i]);
    return 0;
}