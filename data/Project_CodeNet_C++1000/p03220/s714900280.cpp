#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using vi = vector<int>;
template <class T>
using Grid = vector<vector<T>>;

int main(){
    int N, T, A;
    cin >> N >> T >> A;
    double mdif = 1000000000;
    int ans;
    rep(i, N) {
        int h;
        cin >> h;
        double t = T - h * .006;
        if (abs(A-t) < mdif) {
            mdif = abs(A - t);
            ans = i + 1;
        }
    }
    cout << ans << endl;
}