#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=3500;i++){
        for(int j=1;j<=3500;j++){
            ll x=1ll*n*i*j,y=4*i*j-1ll*n*j-1ll*n*i;
            if(y&&x%y==0&&x/y>=1){
                printf("%d %d %lld\n",i,j,x/y);
                return 0;
            }
        }
    }
}