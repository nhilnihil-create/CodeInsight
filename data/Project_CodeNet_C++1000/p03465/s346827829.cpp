#include<bits/stdc++.h>
using namespace std;
bitset<4000005> B;
int n,v,sum;
int main(){
    scanf("%d",&n);
    B[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&v);
        B|=B<<v;
        sum+=v;
    }
    for(int i=(sum+1)/2;i<=sum;i++)
        if(B[i]){
            printf("%d\n",i);
            return 0;
        }
    cout<<"peace & love.";
}