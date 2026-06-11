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

int main() {
    string S; cin >> S;
    int N = S.size();
    int l = 0; int r = N-1;
    int ans = 0;
    while(l < r) {
        //cout << l << " " << r << endl;
        if(S[l] == S[r]) {
            l++; r--;
        } else {
            if(S[l] == 'x') {
                l++; ans++;
            } else if(S[r] == 'x') {
                r--;
                ans++;
            } else {
                //cout << S[l] << " " << S[r] << endl;
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}