#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int a[N],b[N], n, sum1,sum2;
signed main(void){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    for(int i=1;i<=n;i++) scanf("%lld",b+i);
    for(int i=1;i<=n;i++) {
        if(a[i] > b[i]) sum1 += (a[i] - b[i]);
        if(a[i] < b[i]) sum2 += (b[i] - a[i])/2;
    }
    if(sum1 <= sum2) puts("Yes\r");
    else puts("No");
}