/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>
#include <cassert>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll conbinationMemo[100][100];

void cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
//-----------------------ここから-----------
struct SegmentTree{
    ll segTreeSize = 1;
    vector<ll> node;

    void initRMQ(vector<ll> vec){
        while(segTreeSize < (ll)vec.size()){
            segTreeSize *= 2;
        }
        node.resize(2 * segTreeSize - 1, -INF);
        for(ll i = 0; i < (ll)vec.size(); i++){
            node[i + segTreeSize - 1] = vec[i];
        }
        for(ll i = segTreeSize - 2; i >= 0; i--){
            node[i] = max(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void initRSQ(vector<ll> vec){
        while(segTreeSize < (ll)vec.size()){
            segTreeSize *= 2;
        }
        node.resize(2 * segTreeSize - 1, 0);
        for(ll i = 0; i < (ll)vec.size(); i++){
            node[i + segTreeSize - 1] = vec[i];
        }
        for(ll i = segTreeSize - 2; i >= 0; i--){
            node[i] = node[2 * i + 1] + node[2 * i + 2];
        }
    }

    void updateRMQ(ll idx, ll val){
        idx += (segTreeSize - 1);
        node[idx] = val;
        while(idx > 0){
            idx = (idx - 1) / 2;
            node[idx] = max(node[2 * idx + 1], node[2 * idx + 2]);
        }
    }

    void updateRSQ(ll idx, ll val, bool isAdd){
        idx += (segTreeSize - 1);
        node[idx] = (isAdd?node[idx]+val:val);
        while(idx > 0){
            idx = (idx - 1) / 2;
            node[idx] = node[2 * idx + 1] + node[2 * idx + 2];
        }
    }

    ll getRMQ(ll l, ll r, ll idx = 0, ll nowl = 0, ll nowr = -1){
        if(nowr == -1){
            nowr = segTreeSize;
        }

        if(nowr <= l || r <= nowl){
            return -INF;
        }

        if(l <= nowl && nowr <= r){
            return node[idx];
        }

        return max(getRMQ(l, r, 2*idx+1, nowl, (nowl+nowr)/2), getRMQ(l, r, 2*idx+2, (nowl+nowr)/2, nowr));
    }

    ll getRSQ(ll l, ll r, ll idx = 0, ll nowl = 0, ll nowr = -1){
        if(nowr == -1){
            nowr = segTreeSize;
        }

        if(nowr <= l || r <= nowl){
            return 0;
        }

        if(l <= nowl && nowr <= r){
            return node[idx];
        }

        return getRSQ(l, r, 2*idx+1, nowl, (nowl+nowr)/2) + getRSQ(l, r, 2*idx+2, (nowl+nowr)/2, nowr);
    }
};
ll n;
vector<ll> h;
vector<ll> a;
int main(void){
    cin >> n;
    h.resize(n);
    a.resize(n);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> a[i];
    vector<ll> dp(n + 1, -INF);
    dp[0] = 0;
    SegmentTree sgt;
    sgt.initRMQ(dp);
    rep(i, n){
        ll ma = sgt.getRMQ(0, h[i]);
        sgt.updateRMQ(h[i], ma + a[i]);
    }

    cout << sgt.getRMQ(0, n + 1) << endl;
}
