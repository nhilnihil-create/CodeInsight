#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,i,j;

    int n,mn=107,cnt=0;
    cin>>n;
    int a[n+1];

    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<mn) mn=a[i];
    }

    cnt=mn;
    for(i=1;i<=n;i++)
        a[i]-=mn;

    int x;
    for(i=1;i<=n;i++){
        if(a[i]!=0){
            x=a[i];
            cnt+=x;
            int l=i;
            while(a[l+1]!=0 && l<n) l++;

            j=i+1;
            while(j<=l){
                if(a[j]<x){
                    x=a[j];
                    a[j]=0;
                }
                else{
                    a[j]-=x;
                }
                j++;
            }

        }
    }
    printf("%d\n",cnt);





return 0;
}
