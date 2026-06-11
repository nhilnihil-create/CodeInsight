#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100005];
int main() {
    scanf("%s",s+1);
    int n=strlen(s+1);
    if (s[n]=='1'||s[1]=='0'||s[n-1]=='0') {
        puts("-1");
        return 0;
    }
    int now=2;
    while (now<=n-now) {
        if (s[now]!=s[n-now]) {
            puts("-1");
            return 0;
        }
        now++;
    }
    int rt=2,num=1; //num为边的编号
    now=2; //点的编号
    puts("2 1\n");
    while (now<=n-now) {
        if (s[now]=='1') {
            printf("%d %d\n",++now,rt);
            rt=now;
        }
        else {
            printf("%d %d\n",++now,rt);
        }
        num++;
    }
    for (int i=num+1; i<n; i++) printf("%d %d\n",rt,++now);

    return 0;
}