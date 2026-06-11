#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    if(k % 2 == 1) {
        ll ans = 1;
        int c = n / k;
        rep(i,3) {
            ans *= c;
        }
        printf("%ld\n",ans);
        return 0;
    } else {
        ll ans = 0,x = 1,y = 1,counter = 0;
        int c = n / k;
        rep(i,3) {
            x *= c;
        }
        ans += x;
        int h = k / 2;
        for(int i = 1; i <= n; i++) {
            if(i % k == h) {
                counter++;
            }
        }
        rep(i,3) {
            y *= counter;
        }
        ans += y;
        printf("%ld\n",ans);
        return 0;
    }
}