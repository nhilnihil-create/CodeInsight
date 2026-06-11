#include<bits/stdc++.h>
using namespace std;
char s[100005];
int n;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    if(s[1]=='0'||s[n]=='1'){
        puts("-1");
        return 0;
    }
    for(int i=1;i<n;i++)
        if(s[i]^s[n-i]){
            puts("-1");
            return 0;
        }
    int now=1;
    for(int i=2;i<=n;i++){
        printf("%d %d\n",now,i);
        if(s[i-1]=='1')now=i;
    }
}