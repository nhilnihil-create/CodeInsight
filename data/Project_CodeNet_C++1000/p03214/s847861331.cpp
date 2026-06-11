#include <bits/stdc++.h>

using std::cin;
using std::cout;
using LL = long long;
using pii = std::pair<int, int>;

const int mn = 1e5 + 5;
int n;
int a[mn];

int main() {
#ifdef trote
    freopen("../1.txt", "r", stdin);
#endif
    cin.sync_with_stdio(0);
    int sum=0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i],sum+=a[i];
    int d=1e9,who=0;
    for(int i=1;i<=n;i++){
        int delta=abs(a[i]*n-sum);
        if (delta<d){
            who=i;
            d=delta;
        }
    }
    printf("%d\n",who-1);
    return 0;
}