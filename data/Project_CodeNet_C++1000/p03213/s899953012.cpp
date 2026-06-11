#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

vector<int> primeFactorization(int n) {
    vector<int> result;
    int i = 2;
    while (i <= sqrt(n)) {
        if (n%i == 0) {
            result.push_back(i);
            n /= i;
        }
        else i += 1;
    }
    if (n != 1) result.push_back(n);
    return result;
}
lint comb(lint n, lint k) {
    if (n == 0) return 0;
    if (n == k || k == 0) return 1;
    else return comb(n-1, k-1) + comb(n-1, k);
}

int main() {
    int n; cin >> n;
    vector<int> v;
    for (int i=1; i<=n; i++) {
        vector<int> rv = primeFactorization(i);
        v.insert(v.end(), rv.begin(), rv.end());
    }
    map<int,int> cnt;
    rep(i,v.size()) cnt[v[i]] ++;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()),v.end());
    int ans = 0;
    int four = 0;
    int two = 0;
    rep(i,v.size()) {
        if (cnt[v[i]] >= 4) four ++;
        else if (cnt[v[i]] >= 2) two ++;
    }
    ans += comb(four,3) * 3;
    ans += comb(four,2) * two;
    // ここで解説見ました...悔しい
    four = 0;
    two = 0;
    int fourteen = 0;
    int twentyfour = 0;
    int seventyfour = 0;
    rep(i,v.size()) {
        if (cnt[v[i]] >= 4) four ++;
        if (cnt[v[i]] >= 2) two ++;
        if (cnt[v[i]] >= 74) seventyfour++;
        if (cnt[v[i]] >= 24) twentyfour++;
        if (cnt[v[i]] >= 14) fourteen++;
    }
    //ans += fourteen * (four-1);
    //ans += twentyfour * (two-1);
    //ans += seventyfour;
    ans += seventyfour + twentyfour*(two-1) + fourteen*(four-1);
    cout << ans << endl;
}