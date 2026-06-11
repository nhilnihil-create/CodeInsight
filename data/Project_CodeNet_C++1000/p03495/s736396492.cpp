
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int cnt[200010];

int main(){
    int n, k;
    cin >> n >> k;

    rep(i,n){
        int a;
        cin >> a;
        cnt[a-1] ++;
    }
    sort(cnt,cnt+n);
    int ans=0;
    rep(i,n-k){
        ans += cnt[i];
    }

    cout << ans << endl;
}