#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    map<int,int> mp;
    rep(i,N) {
        int a;
        cin >> a;
        ++mp[a];
    }

    int ans = 0;
    for(auto e:mp){
        int f = e.first;
        int s = e.second;
        if(f>s) ans+=s;
        else if(f<s) ans+=(s-f);
    }
    cout << ans << endl;
}