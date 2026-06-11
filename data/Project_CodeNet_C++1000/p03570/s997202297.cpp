#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<map>
#define N 200005
using namespace std;
///map<int,int>ma;
int ma[1<<26];
int i,j,k,l,s,n,m,f[N];
char c[N];
inline int work(int x) {
    if (!x) return 0;
    int s=l+1;
    if (ma[x]) s=f[ma[x]];
    for (int i=0;i<26;i++) if (ma[x^(1<<i)]) s=min(s,f[ma[x^(1<<i)]]);
    else if (x==(1<<i)) return 0;
    return s;
}
int main() {
    scanf("%s",c+1);
    l=strlen(c+1);
    s=0;
    for (i=1;i<=l;i++) {
        s^=(1<<(c[i]-97));
        f[i]=work(s)+1;
        if (!ma[s]&&s) ma[s]=i;
        else if (ma[s]&&f[ma[s]]>f[i]) ma[s]=i;
    }
    printf("%d\n",f[l]);
}
