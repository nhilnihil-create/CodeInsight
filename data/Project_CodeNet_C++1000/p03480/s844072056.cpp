#include<cstdio>
#include<cstring>
#include<iostream>
const int M=120000;
using namespace std;
int a[M],ans;char s[M];
int main(){
    
    scanf("%s",s+1);
    int n=strlen(s+1);
    ans=n;
    for(int i=2;i<=n;i++)
    if(s[i]!=s[i-1])
    ans=min(ans,max(i-1,n-i+1));
    printf("%d",ans);
}
