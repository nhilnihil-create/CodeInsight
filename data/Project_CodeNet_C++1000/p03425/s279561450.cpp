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
    map<char,int>mp;
    rep(i,n) {
        string s;
        cin >> s;
        mp[s[0]]++;
    }
    vector<int>p = {0,0,0,0,0,0,1,1,1,2};
    vector<int>q = {1,1,1,2,2,3,2,2,3,3};
    vector<int>r = {2,3,4,3,4,4,3,4,4,4};
    vector<ll>D(5);
    D[0] = mp['M'];D[1] = mp['A'];D[2] = mp['R'];D[3] = mp['C'];D[4] = mp['H'];
    ll ans = 0;
    rep(i,10) {
        ans += D[p[i]]*D[q[i]]*D[r[i]];
    }
    cout << ans << endl;
}