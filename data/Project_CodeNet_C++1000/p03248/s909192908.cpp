#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX=1e5+5;
struct edge{
    int start,endd;
}h[MAX];
int cnt,n,mian=1,now=1;
char a[MAX];
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    if(a[n]!='0' || a[1]!='1'){
        printf("-1");
        return 0;
    }
    for(int i=1;i<n;i++){
        if(a[i]!=a[n-i]){
            printf("-1");
            return 0;
        }
        h[++cnt]=edge{mian,now+1};
        now++;
        if(a[i]=='1')mian=now;
    }
    for(int i=1;i<=cnt;i++)printf("%d %d\n",h[i].start,h[i].endd);
    return 0;
}