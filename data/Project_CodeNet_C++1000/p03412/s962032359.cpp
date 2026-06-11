#include<bits/stdc++.h>
using namespace std;
const int MAX=200000,MQ=28;
int a[MAX],b[MAX],fin,n;
int mask=0;
bool cmp(int &x,int &y){
    return (x&mask)<(y&mask);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    if(n%2) for(int i=0;i<n;i++) fin^=a[i],fin^=b[i];
    for(int i=0;i<=MQ;i++){
        int val=0;
        mask^=(1<<i);
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        for(int j=0,k=n;j<n;j++){
            for(;(b[k-1]&mask)+(a[j]&mask)>mask&&k>=1;k--);
            val+=n-k;
        }
        if(val%2) fin^=mask+1;
        //printf("%d %d\n",mask+1,val);
    }
    printf("%d\n",fin);
}
