#include<bits/stdc++.h>
using namespace std;
char s[4];
int ans;
int main(){
    scanf("%s",s);
    for(int i=0;i<4;i++)ans+=s[i]=='2';
    printf("%d\n",ans);
    return 0;
}