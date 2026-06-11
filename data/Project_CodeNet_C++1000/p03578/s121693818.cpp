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
    int N; cin >> N;
    vecl D(N); REP(i,N) cin >> D[i];
    int M; cin >> M;
    vecl T(M); REP(i,M) cin >> T[i];
    map<ll,int> mp;
    REP(i,N) {
        mp[D[i]]++;
    }
    REP(i,M) {
        if(mp.count(T[i])) {
            if(mp[T[i]] == 0) {
                cout << "NO" << endl;
                return 0;
            } else mp[T[i]]--;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}