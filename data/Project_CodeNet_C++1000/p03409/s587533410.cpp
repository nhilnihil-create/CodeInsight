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

int main() {
    int N; cin >> N;
    vector<P> red(N),blue(N);
    REP(i,N) cin >> red[i].second >> red[i].first;
    REP(i,N) cin >> blue[i].first >> blue[i].second;
    sort(red.begin(),red.end());
    reverse(red.begin(),red.end());
    sort(blue.begin(),blue.end());
    vector<bool> seen(N,false);
    REP(i,N) {
        int c = blue[i].first;
        int d = blue[i].second;
        REP(j,N) {
            int a = red[j].second;
            int b = red[j].first;
            if(seen[j]) continue;
            if(a < c && b < d) {
                seen[j] = true;
                break;
            }
        }
    }
    int ans = 0;
    REP(i,N) ans += seen[i];
    cout << ans << endl;
}