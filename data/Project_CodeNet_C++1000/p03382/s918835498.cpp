#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;
int abs(int n){
    return (n>=0)?n:-n;
}
int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    int ai=num[n-1];
    int aj=num[0];
    for(int i=0;i<n-1;i++){
        if(abs(num[i]-ai/2)<=abs(aj-ai/2))aj=num[i];
    }
    printf("%d %d\n",ai,aj);

}