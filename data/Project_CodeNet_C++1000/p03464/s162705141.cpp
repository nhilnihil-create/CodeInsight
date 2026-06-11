#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int mod=10000,MAX=203,INF=1<<30;

using namespace std;

int main(){
    ll K;
    cin >> K;
    ll A[K];
    rep(i, K){
        cin >> A[K-i-1];
    }

    ll l = 2;
    ll r = 2;

    rep(i, K){
        if (A[i] > r) {
            cout << -1 << endl;
            return 0;
        } else {
            ll tmp = l / A[i];
            if (tmp > 0 && l % A[i] == 0) {
                l = l;
            } else if (tmp > 0 && A[i] * (tmp + 1) <= r) {
                l = A[i]*(tmp+1);
            } else if (tmp > 0 && A[i] * (tmp + 1) > r){
                cout << -1 << endl;
                return 0;
            } else {
                l = A[i];
            }
            tmp = r / A[i];

            r = A[i] * tmp + A[i] - 1;



        }
//        cout << l << " " << r << endl;
    }
    cout << l << " " << r << endl;
}