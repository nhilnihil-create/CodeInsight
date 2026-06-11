#include<bits/stdc++.h>
using namespace std;

#define sc2(a,b)  scanf("%d %d",&a,&b)

int main(){
    int mod=1000000007;
    int n,k,ans;
    sc2(n,k);
    char s[n];
    scanf("%s",s);
    s[k-1]=tolower(s[k-1]);
    printf("%s\n",s);
    return 0;
}
