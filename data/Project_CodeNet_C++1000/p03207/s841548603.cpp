//url:
//problem name: 

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    cin >> N;
    veci res(N);
    REP(i,N) cin >> res[i];
    sort(res.begin(),res.end(),greater<int>());
    int ans = 0;
    REP(i,N) {
        if(i == 0) ans += res[i]/2;
        else ans += res[i];
    }
    cout << ans << endl;
}
