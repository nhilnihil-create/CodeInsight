#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> a(n);
    vector<int> cs(n+1);
    for (int i = 0; i < n-1; i++) {
        if (s[i] == 'A' && s[i+1] == 'C') a[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cs[i+1] = cs[i] + a[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--;
        r--;
        cout << cs[r] - cs[l] << endl;
    }


}

