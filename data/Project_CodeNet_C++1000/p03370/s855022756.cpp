#include<stdio.h>
#include<stdlib.h>
int main() {
    int arr[100001];
    long long int n,i,x,sum=0,cnt=0,rem,value=0,max=-1;
    scanf("%lld%lld",&n,&x);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n;i++){
        sum+=arr[i];
            cnt=i+1;
    }
    rem=x-sum;
    for(i=0;i<n;i++){
        value=rem/arr[i];
        if(value>max){
            max=value;
        }
    }
    printf("%lld",cnt+max);
    return 0; 
    }