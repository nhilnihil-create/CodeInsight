#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n; cin >> n;
    map<int, int> odd, even;
    rep(i, n){
        int v; cin >> v;
        if(i%2) even[v]++;
        else odd[v]++;
    }

    priority_queue<pii> que_odd, que_even; //first: 出現回数 second: 数
    que_odd.push(pii(0, -1)); que_even.push(pii(0, -1));
    for (auto iter = odd.begin(); iter != odd.end(); iter++) {
        int key = iter->first, num = iter->second;
        que_odd.push(pii(num, key));
    }
    for (auto iter = even.begin(); iter != even.end(); iter++) {
        int key = iter->first, num = iter->second;
        que_even.push(pii(num, key));
    }
    int x = 0, y = 0;
    pii mxOdd = que_odd.top(); que_odd.pop();
    pii mxEven = que_even.top(); que_even.pop();
    if(mxOdd.first == mxEven.first && mxOdd.second == mxEven.second){
        int num = max(que_odd.top().first, que_even.top().first);
        x = num, y = mxOdd.first;
    } else{
        x = mxOdd.first, y = mxEven.first;
    }
    int res = (n/2 - x) + (n/2 - y);
    cout << res << ln;
}

    