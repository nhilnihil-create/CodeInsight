#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000009;
const double pi = acos(-1);

int disit_sum(int a) {
    int ans = 0;
    while(a) {
        ans += a%10;
        a /= 10;
    }
    return ans;
}

int main() {
    int N; cin >> N;
    int ans = 1e9;
    for(int A = 1; A < N; A++) {
        int B = N-A;
        chmin(ans,disit_sum(A)+disit_sum(B));
    }
    cout << ans << endl;
}