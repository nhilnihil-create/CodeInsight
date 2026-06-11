#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc,char** argv){
    int n;
    scanf("%d",&n);
    int b[n],a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            if(j==b[j-1]){
                for(int k=j;k<n;k++)b[k-1]=b[k];
                a[i]=j;
                j=1;
            }else if(j==1){
                printf("-1\n");
                return 0;
            }
        }
    }
    for(int i=n-1;i>=0;i--)printf("%d\n",a[i]);
    return 0;
}


