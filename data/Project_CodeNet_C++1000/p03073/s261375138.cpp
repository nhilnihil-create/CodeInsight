#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int A = 0;
    int B = 0;
    rep(i,n) {
        if(s[i]-'0' != i%2) A++;
        else B++;
    }
    int ans = min(A, B);
    cout << ans << endl;
    return 0;
}   