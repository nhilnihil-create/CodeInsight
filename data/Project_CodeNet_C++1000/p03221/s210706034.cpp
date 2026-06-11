//url:
//problem name: Brick Break

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
    int N,M;
    cin >> N >> M;
    vector<vector<P>> res(N);
    vector<string> ans(M);
    REP(i,M) {
        int p,y; cin >> p >> y;
        res[p-1].push_back(P(y,i));
    }

    REP(i,N) {
        sort(res[i].begin(),res[i].end());
    }

    /*

    for(auto ret:res) {
        for(P p: ret) cout << "(" << p.first << "," << p.second << ") ";
        cout << endl;
    }

    */

    REP(i,N) {
        int cnt = 1;
        if(res[i].size() == 0) continue;
        for(auto x: res[i]) {
            string A = to_string(i+1);
            string B = to_string(cnt);
            REP(j,6-to_string(i+1).size()) A = '0' + A;
            REP(j,6-to_string(cnt).size()) B = '0' + B;
            ans[x.second] = A+B;
            cnt++;
        }
    }

    for(auto a:ans) cout << a << endl;
}