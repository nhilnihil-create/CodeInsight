#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5+15;

int A[N];
ll pre[N];

ll go(int x,int y,int l,int n,int add1,int add2) {
    if(x+add1==y || l+add2==n) {
        return 1e18;
    }
    ll u = pre[x+add1];
    ll i= pre[y]- pre[x+add1];
    ll q = pre[l+add2] - pre[y];
    ll w = pre[n] - pre[l+add2];
    vector<ll> v;
    v.push_back(u);
    v.push_back(i);
    v.push_back(q);
    v.push_back(w);
    sort(v.begin(),v.end());
    return v.back() - v[0];
}

ll solve2(int n) {
    ll ret = 1e18;
    int pos = 1;
    ll cur = A[1];
    for(int i=2;i<=n-2;++i) {
        while(pos+1<i) {
            ll tmp = cur + A[pos+1];
            if(tmp*2 <= pre[i]){
                cur += A[pos+1];
                ++pos;
            } else {
                break;
            }
        }
        int l = i+1,r = n-1,mid;
        ll remSum = pre[n] - pre[i];
        while(l<r) {
            mid = (l+r+1)/2;
            ll tmp = pre[mid] - pre[i];
            if(tmp*2<=remSum) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        for(int q=0;q<2;++q) {
            for(int w=0;w<2;++w) {
                ret = min(ret, go(pos,i,l,n,q,w));
            }
        }
    }
    return ret;
}
void solve() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&A[i]);
        pre[i] = pre[i-1] + A[i];
    }
    ll ret = solve2(n);
    reverse(A+1,A+n+1);
    printf("%lld\n", ret);
}


int main() {
   //freopen("input.txt","r",stdin);
   solve();
}
