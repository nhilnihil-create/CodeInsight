#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
ll a[N],b[N];
int n;
ll sum1,sum2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=1;i<=n;i++)scanf("%lld",b+i);
    for(int i=1;i<=n;i++){
        if(a[i]>b[i])sum1+=(a[i]-b[i]);
        if(a[i]<b[i])sum2+=(b[i]-a[i])/2;
    }
    if(sum1<=sum2)puts("Yes");
    else puts("No");
}