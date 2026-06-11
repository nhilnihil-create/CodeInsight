#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1000000000;

int digit_sum(int x){
    int ret = 0;
    while (x > 9){
        ret += x%10;
        x /= 10;
    }
    ret += x%10;
    return ret;
}


int main() {
    int N;
    cin >> N;
    int ans = INF;
    for (int i=1; i<N; i++){
        chmin(ans, digit_sum(i) +  digit_sum(N-i));
    }
    cout << ans << endl;
}