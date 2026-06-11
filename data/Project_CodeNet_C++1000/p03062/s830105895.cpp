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
    ll sum = 0;
    int cnt = 0;
    ll minv = ll(1e18)+1;
    rep(i,n) {
        cin >> a[i];
        sum += abs(a[i]);
        if(a[i]<0) cnt++;
        minv = min(minv,abs(ll(a[i])));
    }
    if(!(cnt%2)) {
        cout << sum << endl;
        return 0;
    } else {
        cout << sum - 2*minv << endl;
    }

}