#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1000+5;
const int M = 20000+5;

LL dp[M];

struct data {
    int w, s, v;
    bool operator< (data b) {return w+s < b.w + b.s;}
};

data a[N];

int main() {
    int n;
    cin>>n;

    for (int i=1; i<=n; i++)
        cin>>a[i].w>>a[i].s>>a[i].v;

    sort(a+1, a+n+1);
    for (int i=1; i<=n; i++) {
        for (int j=a[i].s; j>=0; j--)
            dp[j+a[i].w] = max(dp[j+a[i].w], dp[j] + a[i].v);
    }

    long long ans = 0;
    for (int i=0; i<M; i++)
        ans = max(ans, dp[i]);
    cout<<ans<<endl;
}
