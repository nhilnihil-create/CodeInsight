#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int d,evenum;
    cin >> d;
    evenum = 0;
    string ans;
    ans = "Christmas";
    d = 25-d;
    rep(i,d){
        ans += " Eve";
    }
    cout << ans << endl;
}