#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    string s;
    ll k;
    cin >> s >> k;
    string ans = "1";
    for(int i = 0;i<k;i++) {
        if(s[i] != '1') {
            ans = s[i];
            break;
        }    
    }
    cout << ans << endl;
}