//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N,M;
    cin >> N >> M;
    vector<P> res(M);
    REP(i,M) {
        int a,b;
        cin >> a >> b;
        res[i].first = b;
        res[i].second = a;
    }
    sort(res.begin(),res.end());
    int ans = 0;
    int pre = -1;
    REP(i,M) {
        if(res[i].second >= pre) {
            ans++;
            pre = res[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}

