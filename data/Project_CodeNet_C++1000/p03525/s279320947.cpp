#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define mem(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, int> pli;

const int mn = 3e5 + 5;
const int maxlog = 19;

int n;
int a[55];
int cnt[15];

int main() {
    //cin.sync_with_stdio(0);
#ifdef trote
    freopen("../1.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    scanf("%d",&n);
    cnt[0]++;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=0;i<=12;i++){
        if (cnt[i]>=3) {
            puts("0");
            return 0;
        }
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=0;i<(1<<12);i++){
        vector<int> v;
        for(int j=0;j<=12;j++){
            if (cnt[j]==2){
                v.pb(j);
                v.pb(24-j);
            }
            else if (cnt[j]==1){
                if ((1<<j)&i) v.pb(24-j);
                else v.pb(j);
            }
        }
        sort(all(v));
        v.pb(24);
        int uans=25;
        for(int i=1;i<sz(v);i++){
            uans=min(uans,v[i]-v[i-1]);
        }
        ans=max(ans,uans);
    }
    printf("%d\n",ans);
    return 0;
}