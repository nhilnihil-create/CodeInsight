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

    int ans = 0;
    map<int,int>mp;
    rep(i,n) {
        int a;
        cin >> a;
        if(a>100000) {
            ans++;
            continue;
        }
        mp[a]++;
    }
    for(int i = 1;i<=100000;i++) {
        if(i<mp[i]) ans += mp[i] - i;
        else if(i > mp[i]) ans += mp[i];
    }
    cout << ans << endl;
}