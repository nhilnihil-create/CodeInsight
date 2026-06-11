#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N,K;
    cin >> N >> K;
    deque<int> dq;
    rep(i,N) {
        int v;cin>>v;
        dq.push_back(v);
    }
    int ans = 0;
    rep(l,N+1)rep(r,N+1){
        if(l+r>N||l+r>K) continue;
        int k = max(K-(l+r),0);
        deque<int> d;
        d = dq;
        vec<int> v;
        rep(i,l){
            v.push_back(d.front());
            d.pop_front();
        }
        rep(i,r){
            v.push_back(d.back());
            d.pop_back();
        }
        sort(all(v));
        int tmpans = accumulate(all(v),0);
        rep(i,min(k,(int)v.size())) if(v[i]<0) tmpans-=v[i];
        ans = max(ans,tmpans);
    }
    cout << ans << endl;
}