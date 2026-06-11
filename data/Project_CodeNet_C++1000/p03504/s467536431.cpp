#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n, cc;

int main() {
    cin >> n >> cc;
    vector< vector<int> > imos(cc, vector<int>(200200, 0));
    for(int i = 0; i < n; ++i) {
        int sv, tv, cv; cin >> sv >> tv >> cv;
        cv--; sv *= 2; tv *= 2;
        if(sv != 0) sv--;
        imos.at(cv).at(sv)++;
        imos.at(cv).at(tv+1)--;
    }

    for(int i = 0; i < cc; ++i) {
        for(int j = 0; j < 200020; ++j) {
            imos.at(i).at(j+1) += imos.at(i).at(j);
        }
    }

    int ans = 1;
    for(int i = 0; i < 200020; ++i) {
        int sum = 0;
        for(int j = 0; j < cc; ++j) {
            if(imos.at(j).at(i) >= 1) sum++;
        }
        chmax(ans, sum);
    }

    cout << ans << endl;
}