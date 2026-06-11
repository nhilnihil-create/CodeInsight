#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;

char s[maxn];

int main()
{
    while(~scanf("%s", &s)){
        int ca=0, cb=0, cc=0;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]=='a')ca++;
            if(s[i]=='b')cb++;
            if(s[i]=='c')cc++;
        }
        int mi=min(ca, cb);
        mi=min(mi, cc);
        ca-=mi;
        cb-=mi;
        cc-=mi;
        if(ca<2&&cb<2&&cc<2){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
