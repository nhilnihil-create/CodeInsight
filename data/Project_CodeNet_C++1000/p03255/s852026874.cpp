#include <bits/stdc++.h>
using namespace std;


long long a[200005];
long long n,x;
long long pre[200005];

long long f(long long x){
    if(x==1)return 5;
    return (2*x+1);
}

int main() {
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i]+=a[i];
        pre[i+1] = pre[i];
    }
    long long mn = 1e18;
    for(int k=1;k<=n;k++){
        bool take = true;
        long long ans = 0;
        int cur = 1;
        for(int i=n;i>0;i-=k){
            ans+=(pre[i]-pre[max(0,i-k)])*f(cur);
            if(ans>mn){
                take = false;
                break;
            }
            cur++;
        }
        mn = min(ans+k*x,mn);
    }
    cout << mn+n*x;
    return 0;
}
