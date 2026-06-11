#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&a,&b);
        int tmp = (int)sqrt(1ll*a*b);
        int ans = 2*(int)sqrt(1ll*a*b)-1;
        if (1ll*tmp*tmp == 1ll*a*b && a != b) ans--;
        if (1ll*tmp*(tmp+1) >= 1ll*a*b) ans--;
        printf("%d\n",ans);
    }
    return 0;
}