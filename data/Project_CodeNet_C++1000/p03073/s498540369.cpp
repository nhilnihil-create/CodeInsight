#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define loop(i, a, b) for(lli i=a; i<b; i++)
#define loopb(i, a, b) for(lli i=a; i>=b; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pb push_back
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vll;
#define umap unordered_map
#define all(x) x.begin(), x.end()
// use to avoid collision
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://x...content-available-to-author-only...i.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// for pair in unordered_map
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
lli M = 1e9 + 7;
lli power(lli x, lli y){
    lli res = 1;
    x = x%M;
    while (y > 0) {
        if (y & 1)
            res = (res*x)%M ;
        y = y>>1;
        x = (x*x)%M ;
    }
    return res%M;
}
lli check(string& s, int flag){
    lli n = s.size();
    lli cnt = 0;
    loop(i, 0, n){
        if(s[i] - '0' != flag)
            cnt++;
        flag = 1 - flag;
    }
    return cnt;
}
lli solve(){
    string s;
    cin>>s;
    lli cnt = check(s, 0);
    cnt = min(cnt, check(s, 1));
    cout<<cnt<<"\n";
    return 0;
}
int main(){
    fastio;
    lli t;
	// cin>>t;
    t = 1;
    while(t>0){ 
        t--;
        solve();
    }
}