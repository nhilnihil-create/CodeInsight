#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define F first
#define S second
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define pdd pair<ld, ld>
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define FILE ifstream in("input.txt");ofstream out("output.txt");
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    fast;
    ll a; cin>>a;
    vec<ll> dp(1<<a), kek(1<<a);
    vec<vec<ll>> m(a, vec<ll>(a));
    for(int q=0; q<a; q++){
        for(int w=0; w<a; w++) cin>>m[q][w];
    }
    int all = 1<<a, ost;
    for(int msk=1; msk<all; msk++){
        for(int q=0; q<a; q++){
            if(!(msk&(1<<q))) continue;
            for(int w=q+1; w<a; w++){
                if(!(msk&(1<<w))) continue;
                kek[msk] += m[q][w];
            }
        }
        for(int sub=msk; ; sub = (sub-1)&msk){
            ost = msk^sub;
            dp[msk] = max(dp[msk], dp[sub]+kek[ost]);
            if(sub==0) break;
        }
    }
    cout<<dp[all-1];
}