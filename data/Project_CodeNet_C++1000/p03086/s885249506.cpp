#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)

int main(){
    int ans=0,chk=0;
    char s[15];
    scanf("%s",s);
    rep (i,10) {
        if (s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T') {
            chk++;
        } else {
            chk=0;
        }
        ans=max(ans,chk);
    }
    printf("%d\n",ans);
    return 0;
}
