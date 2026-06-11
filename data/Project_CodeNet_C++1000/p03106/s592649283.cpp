#include<bits/stdc++.h>
using namespace std;

#define sc3(a,b,c)  scanf("%d %d %d",&a,&b,&c)

int main(){
    int a,b,k,n,m,ans;
    sc3(a,b,k);
    for (int i=100;i>0;i--) {
        if (a%i==0 && b%i==0) k--;
        if (k==0) {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
