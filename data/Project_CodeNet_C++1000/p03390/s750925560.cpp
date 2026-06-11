#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
 
int main() {
    int q;
    LL a, b, ans;
    scanf("%d", &q);
    while (q--) {
        scanf("%lld%lld", &a, &b);
        if (a > b) swap(a, b);
        if (a == b) {
            ans = 2 * (a - 1);
        }
        else if (a == b - 1) {
            ans = 2 * (a - 1);
        }
        else {
            LL c = sqrt(a * b);
            if (c * c == a * b) c--;
            if(c * (c + 1) >= a * b) {
                ans = 2 * c - 2;
            }
            else {
                ans = 2 * c - 1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}