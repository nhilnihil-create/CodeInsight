#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

struct abdata {
    int a, b;
};

int main() {
    int n; cin >> n;
    vector<abdata> ans;
    if(n%2 == 0) {
        // 偶数
        int tar = n+1;
        for(int i = 1; i < n; ++i) {
            for(int j = i+1; j <= n; ++j) {
                if(i+j != tar) {
                    abdata indata;
                    indata.a = i; indata.b = j;
                    ans.emplace_back(indata);
                }
            }
        }
    }else {
        // 奇数
        int tar = n;
        for(int i = 1; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if(i+j != tar) {
                    abdata indata;
                    indata.a = i; indata.b = j;
                    ans.emplace_back(indata);
                }
            }
            abdata last;
            last.a = i; last.b = n;
            ans.emplace_back(last);
        }
    }

    int anslen = ans.size();
    cout << anslen << endl;
    for(int i = 0; i < anslen; ++i) {
        cout << ans[i].a << " " << ans[i].b << endl;
    }
}