#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    vector<int>b(n);
    rep(i,n) {
        b[i] = a[i]-(i+1);
    }
    sort(b.begin(),b.end());
    int med = b[n/2];
    ll ans = 0;
    rep(i,n) {
        ans += abs(a[i] - (med+i+1));
    }
    cout << ans << endl;
}
