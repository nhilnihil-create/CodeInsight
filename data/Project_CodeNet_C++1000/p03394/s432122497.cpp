#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
bool v[30005];
int n,a[20005],t;
 
int main(){
    scanf("%d",&n);
    if(n==3){ puts("2 5 63"); return 0;}
    for(int i=2;i<n;i+=2) if((n-i)<=15000&&i<=5000&&(n-i)%3!=1){
        for(int j=2,c=1;j<=30000&&c+i<=n;j+=2,c++) printf("%d ",j);
        for(int j=3,c=1;j<=30000&&c<=i;j+=3) if(j&1) printf("%d ",j),c++;
        break;
    }
    return 0;
}