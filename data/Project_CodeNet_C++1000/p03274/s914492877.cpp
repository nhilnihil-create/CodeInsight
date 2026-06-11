#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,k;
    cin >> n >>k;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    int ans = 1001001001;
    for(int i = 0;i<n-k+1;i++) {
        ans = min(ans,abs(a[i])+abs(a[i]-a[i+k-1]));
        ans = min(ans,abs(a[i+k-1])+abs(a[i+k-1]-a[i]));
    }
    cout << ans << endl;
}