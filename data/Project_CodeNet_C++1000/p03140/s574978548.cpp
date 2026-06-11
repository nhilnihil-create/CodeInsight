#include<cstdio>
char a[105],b[105],c[105];

int main(){
    int n;
    scanf("%d%s%s%s",&n,a+1,b+1,c+1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]==b[i] && b[i]==c[i]) continue;
        else if(a[i]==b[i] || a[i]==c[i] || b[i]==c[i]) ans++;
        else ans += 2;
    }
    printf("%d\n",ans);
    return 0;
}
