#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    k--;
    s[k] = s[k] - 'A' + 'a';
    cout << s << endl;
    return 0;
}