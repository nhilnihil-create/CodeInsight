#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)

int main(){
    int mod=1000000007;
    int x=0,ans=mod;
    char s[100005];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++) {
        if (i%2==0 && s[i]!='0') x++;
        if (i%2 && s[i]!='1') x++;
    }
    ans=min(ans,x);
    x=0;
    for(int i=0;i<strlen(s);i++) {
        if (i%2 && s[i]!='0') x++;
        if (i%2==0 && s[i]!='1') x++;
    }
    ans=min(ans,x);
    printf("%d\n",ans);
    return 0;
}
