#include <bits/stdc++.h>
#define int long long
using namespace std;
struct que {
    int x,num;
    friend bool operator<(que a,que b) {
        return a.x<b.x;
    }
};
priority_queue<que> q;
int n,m,cnt,ans;
signed main() {
    int x,y;
    scanf("%lld%d",&n,&m);
    for(register int i=1; i<=n; i++) {
        scanf("%lld",&x);
        q.push(que {x,1});
    }
    for(register int i=1; i<=m; i++) {
        scanf("%lld%lld",&x,&y);
        q.push(que {y,x});
    }
    while(!q.empty()) {
        que u=q.top();
        q.pop();
        if(cnt+u.num>=n) {
            ans+=(n-cnt)*u.x;
            //cout<<n-cnt<<' '<<u.x<<endl;
            break;
        }
        cnt+=u.num;
        ans+=u.num*u.x;
        //cout<<u.num<<' '<<u.x<<endl;
    }
    printf("%lld",ans);
    return 0;
}
