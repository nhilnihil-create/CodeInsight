#include<bits/stdc++.h>
using namespace std;

#define sc1(a)  scanf("%d",&a)

int main(){
    int n,ans=0,chk;
    sc1(n);
    for (int i=1;i<=n;i++) {
        chk=0;
        for (int j=1;j<=i;j++) {
            if (i%j==0) chk++;
        }
        i++;
        if (chk==8) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
