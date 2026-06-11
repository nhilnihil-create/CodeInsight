#include<bits/stdc++.h>
using namespace std;

typedef pair<string,string> P;

int main() {
    int n;
    long long ans = 0;
    string s;
    map<P,long long> cnt;
    cin >> n >> s;

    for (int i = 0;i < 1 << n;++i) {
        string a = "",b = "";
        for (int j = 0;j < n;++j) {
            if (i & (1 << j)) {
                a += s[j];
            } else b = s[j]+b;
        }
        cnt[P(a,b)]++;
    }

    for (int i = 0;i < 1 << n;++i) {
        string a = "",b = "";
        for (int j = 0;j < n;++j) {
            if (i & (1 << j)) {
                a += s[n+j];
            } else b = s[n+j]+b;
        }
        ans += cnt[P(b,a)];
    }

    cout << ans << endl;
    return 0;
}