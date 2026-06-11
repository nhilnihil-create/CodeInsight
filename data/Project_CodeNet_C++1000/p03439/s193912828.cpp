#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    bool even_is_man = false;
    int ok, ng;
    for (int i = 0; ; ++i) {
        if (i == 0) {
            cout << 0 << endl;
            fflush(stdout);
            string s;
            cin >> s;
            if (s == "Vacant") {
                return 0;
            }
            if (s == "Male") even_is_man = true;
            ok = -1;
            ng = n;
        } else {
            int mid = (ok + ng) / 2;
            cout << mid << endl;
            fflush(stdout);
            string s;
            cin >> s;
            if (s == "Vacant") {
                return 0;
            }
            if (s == "Male") {
                if (even_is_man) {
                    if (mid % 2 == 0) {
                        ok = mid;
                    } else {
                        ng = mid;
                    }
                } else {
                    if (mid % 2 == 0) {
                        ng = mid;
                    } else {
                        ok = mid;
                    }
                }
            } else {
                if (even_is_man) {
                    if (mid % 2 == 0) {
                        ng = mid;
                    } else {
                        ok = mid;
                    }
                } else {
                    if (mid % 2 == 0) {
                        ok = mid;
                    } else {
                        ng = mid;
                    }
                }
            }     
        } 
    }
}