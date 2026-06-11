#include <bits/stdc++.h>
#include <string>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int sum=0;
    for(int i=1; i<=n; i++) {
        string s=to_string(i);
        int ibuff=0;
        rep(i,s.size()) {
            ibuff += s[i]-'0';
        }
        if (a<=ibuff && ibuff<=b) {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}