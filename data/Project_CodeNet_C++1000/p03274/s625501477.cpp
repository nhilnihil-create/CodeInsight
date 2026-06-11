#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n);
    rep(i,n) {
        scanf("%d",&a[i]);
    }
    int limit = n - k + 1;
    ll counter = 0;
    ll ans = 1000000000;
    rep(i,limit) {
        counter += abs(a[i+k-1] - a[i]);
        counter += min(abs(0-a[i]),abs(0-a[i+k-1]));
        ans = min(ans,counter);
        counter = 0;
    }
    printf("%ld\n",ans);
}