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
    int R,G,B,N; cin >> R >> G >> B >> N;
    int ans = 0;
    for(int i = 0; i <= N; i += R) {
        for(int j = 0; j <= N-i; j += G) {
            int rest = N - (i+j);
            if(rest%B == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
