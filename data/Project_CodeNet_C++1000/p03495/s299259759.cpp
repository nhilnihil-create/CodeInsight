#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N,K;
    cin >> N >> K;
    map<int,int> mp;
    rep(i, N) {
        int a;
        cin >> a;
        ++mp[a];
    }
    vec<int> cnts;
    int nowK = 0;
    for(auto e:mp){
        cnts.push_back(e.second);
        ++nowK;
    }
    sort(all(cnts));
    int ans = 0;
    rep(i,nowK-K){
        ans+=cnts[i];
    }
    cout << ans << endl;
}