#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n){
        cin >> x[i];
        y[i] = x[i];
    }
    sort(x.begin(), x.end());
    int m1 = x[n/2-1], m2 = x[n/2];
    rep(i,n){
        if(y[i] <= m1) cout << m2 << endl;
        else cout << m1 << endl;
    }
    return 0;
}
