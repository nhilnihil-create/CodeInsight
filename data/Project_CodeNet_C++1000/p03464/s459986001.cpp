#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    ll l = 2, r = 2;
    for (int i = n-1; i >= 0; i--){
        ll x = ((l-1)/a[i]+1)*a[i];
        ll y = (r/a[i])*a[i];
        //printf("%d %d\n",x,y);
        if (x > r || y < l){
            printf("-1\n");
            return 0;
        }
        l = x;
        r = y+a[i]-1;
    }
    printf("%lld %lld\n",l,r);
}
