#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b[1005],c,fg;
char s[1006];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        if((a[i]+b[i])&1)c++;
        else c--;
    }
    if(abs(c)!=n){
        puts("-1");
        return 0;
    }
    m=31+(c<0);
    printf("%d\n",m);
    for(int i=0;i<=30;i++)printf("%d ",(1<<i));
    if(c<0)printf("1");
    puts("");
    for(int i=1;i<=n;i++){
        int x=a[i],y=b[i];
        if(c<0)s[31]='R',x--;
        fg=0;
        for(int j=30;j>=0;j--){
            if(abs(x)<abs(y)){
                swap(x,y);
                fg^=1;
            }
            if(x>0){
                x-=(1<<j);
                s[j]=fg?'U':'R';
            }
            else{
                x+=(1<<j);
                s[j]=fg?'D':'L';
            }
        }
        printf("%s\n",s);
    }
}