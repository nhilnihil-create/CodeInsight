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
    string ans = "";
    while(n) {
        if(n%2==0) {
            ans += "0";
            n /= -2;
        } else {
            ans += "1";
            n--;
            n /= -2;
        }
    }
    if(ans == "") ans += "0";
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
