#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    vector<int>a(3);
    rep(i,3) cin >> a[i];
    int ans = 0;
    while(a[0] != a[1] || a[0] != a[2] || a[1] != a[2]) {
        sort(a.begin(),a.end());
        if(a[1] != a[2]) {
            a[0]++;
            a[1]++;
        }
        else a[0] += 2;
        ans++;
    }
    cout << ans << endl;
}