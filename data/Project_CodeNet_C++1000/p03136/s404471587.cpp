#include<stdio.h>
#include<stdlib.h>
int main() {
    int arr[101];
    long long int n,i,max,sum=0,fsum;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    max=arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>=max){
            max=arr[i];
        }
    }
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    fsum=abs(sum-max);
    if(fsum>max)
    printf("Yes");
    else 
    printf("No");
    return 0; 
    }