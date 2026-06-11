#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string ans;
    if (N==0) {
        cout << "0" << "\n";
        return 0;
    }
    while (N!=0){
        int p = abs(N);
        if (p%2==1) {
            ans.push_back('1');
            N -= 1;
        } else ans.push_back('0');
        N /= -2;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
}