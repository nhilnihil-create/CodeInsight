#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;

    ll l[n], r[n];
    rep(i,n)cin >> l[i] >> r[i];

    sort(r,r+n);
    sort(l,l+n,greater<ll>());

    ll tmp1 = 0, tmp2 = 0;

    ll now = l[0];
    tmp1 += abs(now);

    int i = 0;
    while(true){
        if(now <= r[i])break;
        tmp1 += now - r[i];
        now = r[i];
        i++;
        if(i == n)break;
        if(l[i] <= now)break;
        tmp1 += l[i] - now;
        now = l[i];
    }

    tmp1 += abs(now);

    now = r[0];
    tmp2 += abs(now);

    i = 0;
    while(true){
        if(l[i] <= now)break;
        tmp2 += l[i] - now;
        now = l[i];
        i++;
        if(i == n)break;
        if(now <= r[i])break;
        tmp2 += now - r[i];
        now = r[i];
    }

    tmp2 += abs(now);

    ll ans = max(tmp1, tmp2);
    cout << ans << endl;
    return 0;
}
 
 
