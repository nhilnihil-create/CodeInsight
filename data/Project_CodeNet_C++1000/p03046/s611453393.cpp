
#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){
    int M;
    ll K;
    cin >> M >> K;
    ll t = 1;
    rep(i, M){
        t *= 2;
    }
    if (K >= t){
       cout << -1 << endl;
    } else if (M == 0) {
        cout << 0 << " " << 0 << endl;
    } else if (M == 1 && K == 0) {
        cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
    } else if (M == 1 && K == 1) {
        cout << -1 << endl;
    } else {
        rep(i, t) {
            if (i == K) continue;
            cout << i << " " ;
        }
        cout << K << " ";
        rep(i, t) {
            if (t-i-1 == K) continue;
            cout << t-i-1 << " ";
        }
        cout << K << " " << endl;

    }
}