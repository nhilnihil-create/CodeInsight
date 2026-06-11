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
    vector<int>t(n);
    vector<int>x(n);
    vector<int>y(n);
    rep(i,n) {
        cin >> t[i] >> x[i] >> y[i];
    }
    bool ans = true;
    rep(i,n) {
        if(t[i]< x[i]+y[i]) ans = false;
        if(t[i]%2 != (x[i]+y[i])%2) ans = false;
        if(i==n-1) continue;
        if(abs(t[i]-t[i+1]) < abs(x[i]-x[i+1])+abs(y[i]-y[i+1])) ans = false;        
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}