#include<bits/stdc++.h>
using namespace std;
const int N =2e5+100;
typedef long long ll;

int main()
{
    int x[N]={0},n;
    ll ans =0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int l=1,r=1,now=0;r<=n;){
        for(;!(now&x[r])&&r<=n;){
            now |=x[r++];
            ans +=r-l;
        }
        now ^=x[l++];
    }
    printf("%lld\n",ans);
}
