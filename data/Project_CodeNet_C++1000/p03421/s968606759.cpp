#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int n,a,b;
bool memo[300001]={true};

signed main() {
    scanf("%d%d%d",&n,&a,&b);
    if (n > a*b || n < a+b-1) puts("-1");
    else {
        int now=b,cnt=n;
        while(1) {
            rep(i,b) {
                if (i==b-1) a--;
                cnt--;
                printf("%d ",now-i);
                memo[now-i] = true;
                if (a == cnt) {
                    rep(k,n+1) if (!memo[k]) printf("%d ",k);
                    return 0;
                }
            }
            now = min(n,now+b);
        }
    }
}
