#include<bits/stdc++.h>
using namespace std;
bitset<2000010> f;
int n,sum;
int a[2005];
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        sum += a[i];
    }
    f[0] = 1;
    for(int i = n;i >= 1;i--) f |= f << a[i];
    for(int i = (sum+1) >> 1;i <= sum;i++){
        if(f[i]){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}