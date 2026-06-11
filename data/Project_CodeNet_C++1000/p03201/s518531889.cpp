#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 400005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for (auto &i : A) cin >> i;

    sort(A.begin(), A.end(), greater<int>());

    auto f = [](int n){
        int res = 1;
        while (res <= n) res *= 2;
        return res;
    };

    int ans = 0;
    map<int, int> count;
    for (auto &i : A) count[i]++;

    for (auto &i : A) {
        if (count[i] == 0) continue;
        int X = f(i);
        int n = X - i;
        if (count[n] == 0) continue;
        if (i == n && count[i] <= 1) continue;
        ans++;
        count[i]--;
        count[n]--;
    }

    cout << ans << endl;
}