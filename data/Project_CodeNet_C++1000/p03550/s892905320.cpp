#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,z,w,pok[2001];
    scanf("%d%d%d",&n,&z,&w);
    for(int i=0;i<n;i++)scanf("%d",&pok[i]);
    if(n==1)printf("%d\n",abs(pok[n-1]-w));else printf("%d\n",max(abs(pok[n-1]-pok[n-2]),abs(pok[n-1]-w)));
    return 0;
}