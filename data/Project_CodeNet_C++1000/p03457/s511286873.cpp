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
    vector<int>t(n+1);
    vector<int>x(n+1);
    vector<int>y(n+1);
    rep(i,n) {
        cin >> t[i] >> x[i] >> y[i];
    }
    bool ans = true;
    rep(i,n) {
        int dt = abs(t[i]-t[i+1]);
        int dx = abs(x[i]-x[i+1]);
        int dy = abs(y[i]-y[i+1]);
        if(dt < dx+dy || dt%2 != (dx+dy)%2) {
            ans = false;        
            break;
        }          
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}