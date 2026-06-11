#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    long long x[n],y[n];
    long long p=1000000000;
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    int o=0;
    for(int i=0;i<n-1;i++){
        if(((x[i]+y[i]+2*p)%2)!=((x[i+1]+y[i+1]+2*p)%2))o=1;
    }
    if(o){
        printf("-1\n");
        return 0;
    }
    if((x[0]+y[0]+2*p)%2==0){
        o=1;
    }
    printf("%d\n",o+31);
    if(o)printf("1 ");
    long long bi[35];
    bi[0]=1;
    for(int i=0;i<33;i++){
        bi[i+1]=bi[i]*2;
    }
    for(int i=30;i>0;i--){
        printf("%lld ",bi[i]);
    }
    printf("1\n");
    for(int i=0;i<n;i++){
        if(o){
            x[i]++;
            printf("L");
        }
        for(int j=30;j>0;j--){
            if(y[i]>x[i]&&y[i]>0-x[i]){
                printf("U");
                y[i]-=bi[j];
            }
            else if(y[i]<x[i]&&y[i]<0-x[i]){
                printf("D");
                y[i]+=bi[j];
            }
            else if(x[i]>y[i]&&x[i]>0-y[i]){
                printf("R");
                x[i]-=bi[j];
            }
            else if(x[i]<y[i]&&x[i]<0-y[i]){
                printf("L");
                x[i]+=bi[j];
            }
        }
        if(x[i]==1)printf("R\n");
        if(x[i]==-1)printf("L\n");
        if(y[i]==1)printf("U\n");
        if(y[i]==-1)printf("D\n");
    }
}