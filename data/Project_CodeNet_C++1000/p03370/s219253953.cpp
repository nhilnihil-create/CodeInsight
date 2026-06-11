#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main(){
    int N, X;
    cin >> N >> X;
    int sum = 0, m = INT_MAX;
    rep(i,N) {
        int a;
        cin >> a;
        sum += a;
        m = min(m, a);
    }
    X -= sum;
    int ans = N;
    ans += X / m;
    cout << ans << endl;
}