#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod = 1000000007;
const int MX = 2e3+1;
bitset<MX*MX>bs;
int main(){
    bs[0]=1;
    int n,s=0,sc;scanf("%d",&n);for(int i=1;i<=n;i++){
        scanf("%d",&sc);bs=bs|(bs<<sc);s+=sc;
    }
    for(int i=(s+1)/2;i<=s;i++)if(bs[i]){printf("%d",i);break;}
    return 0;
}
