#include<bits/stdc++.h>
using namespace std;
bitset<2000002>f;
int n,i,x,s;
int main(){
    scanf("%d",&n),f[0]=1;
    for (;n--;){
        scanf("%d",&x),s+=x;
        f|=f<<x;
    }
    for (i=(s+1)/2;i<=s;i++)
        if (f[i]) return printf("%d",i),0;
}