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
    int N,T;
    cin >> N >> T;
    vector<pair<int,int>> res(N);
    for(int i = 0; i < N; i++) {
        int c,t;
        cin >> c >> t;
        res[i].first = c;
        res[i].second = t;
    }
    sort(res.begin(),res.end());
    //for(auto p : res) cout << p.first << " "<< p.second << endl;
    for(P p : res) {
        if(p.second <= T) {
            cout << p.first << endl;
            return 0;
        }
    }
    cout << "TLE" << endl;
}
