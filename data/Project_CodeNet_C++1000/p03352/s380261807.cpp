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
    int x; cin >> x;
    vector<int> list{1};
    for(int i=2; i<=x; i++){
        int num = i;
        while(num <= x){
            num *= i;
            list.push_back(num);
        }
    }
    sort(all(list));
    auto iter = upper_bound(all(list), x);
    int res = *(--iter);
    cout << res << ln;
}