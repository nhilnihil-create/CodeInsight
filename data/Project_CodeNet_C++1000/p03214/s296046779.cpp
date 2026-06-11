#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105];

int main(){
    scanf("%d",&n);
    ll sum=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    ll mx=1e9;
    int ans=0;
    for (int i=1;i<=n;i++)
    {

        if (abs(a[i]*n-sum)<mx)
        {
            mx=abs(a[i]*n-sum);
            ans=i;
        }
    }

    printf("%d\n",ans-1);
}
