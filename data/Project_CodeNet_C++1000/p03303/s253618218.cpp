#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[2000],pr[2000];
    int w,k=0,m;
    cin>>s>>w;
    m=strlen(s);
    for(int i=0;i<=m;i+=w)
    {
        pr[k]=s[i];
        k++;
    }
    pr[k]='\0';
    for(int i=0;pr[i]!='\0';i++){
        printf("%c",pr[i]);
    }
    cout<<"\n";
    return 0;
}
