#include<cstdio>
int main(){
    int n,k=3;
    scanf("%d",&n);
    if(n==1){
        printf("Yes\n2\n1 1\n1 1");
        return 0;
    }
    while(k*(k-1)/2<n)k++;
    if(k*(k-1)/2!=n){
        printf("No");
        return 0;
    }
    printf("Yes\n%d\n",k);
    printf("%d ",k-1);
    for(int i=1;i<k;i++)printf("%d ",i*(i+1)/2);
    printf("\n");
    for(int i=1;i<k;i++){
        printf("%d ",k-1);
        for(int j=i*(i-1)/2+1;j<=i*(i+1)/2;j++)printf("%d ",j);
        for(int j=i;j*(j+1)/2+i<=n;j++)printf("%d ",j*(j+1)/2+i);
        printf("\n");
    }
    return 0;
}