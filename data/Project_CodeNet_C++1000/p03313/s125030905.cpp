#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int maxm = maxn*10;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int n,a[1<<18],b[1<<18],ans,cnt;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 0;i<(1<<n);++i) cin>>a[i];
    for(int i = 0;i<n;i++) 
        for(int j = 0;j<(1<<n);j++)
            if((j>>i)&1)
                if(a[j] > a[j^(1<<i)]) b[j] = max(b[j],a[j^(1<<i)]);
                else {
                    b[j] = max(a[j],b[j^(1<<i)]);
                    a[j] = a[j^(1<<i)];
                }
    int ans = 0;
    for(int i = 1;i<(1<<n);i++) {
        ans = max(ans,a[i] + b[i]);
        printf("%d\n",ans);
    }
}