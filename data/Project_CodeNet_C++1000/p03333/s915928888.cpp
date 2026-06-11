#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> l(n), r(n), idx1(n), idx2(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        idx1[i] = i;
        idx2[i] = i;
    }
 
    sort(idx1.begin(), idx1.end(), [&](const int& i1, const int& i2){return l[i1] > l[i2];});
    sort(idx2.begin(), idx2.end(), [&](const int& i1, const int& i2){return r[i1] < r[i2];});
 
    vector<int> used(n, false);
    int pos = 0;
    ll ans = 0;
    int hoge = 1;
    for (int i = 0, j = 0; i < n || j < n;) {
        int tmp1 = 0, np1 = pos;
        while (i < n) {
            if (!used[idx1[i]]) {
                if (pos < l[idx1[i]]) {
                    tmp1 = l[idx1[i]] - pos;
                    np1 = l[idx1[i]];
                } else if (pos > r[idx1[i]]) {
                    tmp1 = pos - r[idx1[i]];
                    np1 = r[idx1[i]];
                }
                break;
            }
            i++;
        }
        
        int tmp2 = 0, np2 = pos;
        while (j < n) {
            if (!used[idx2[j]]) {
                if (pos < l[idx2[j]]) {
                    tmp2 = l[idx2[j]] - pos;
                    np2 = l[idx2[j]];
                } else if (pos > r[idx2[j]]) {
                    tmp2 = pos - r[idx2[j]];
                    np2 = r[idx2[j]];
                }
                break;
            }
            j++;
        }
 
        if (i == n && j == n) break;
        if (hoge == -1) {
            used[idx1[i]] = true;
            ans += tmp1;
            pos = np1;
            hoge = 1;
        } else {
            used[idx2[j]] = true;
            ans += tmp2;
            pos = np2;   
            hoge = -1;
        }
    }
    ans += abs(pos);
 
    pos = 0;
    hoge = -1;
    used.assign(n, false);
    ll ans2 = 0;
    for (int i = 0, j = 0; i < n || j < n;) {
        int tmp1 = 0, np1 = pos;
        while (i < n) {
            if (!used[idx1[i]]) {
                if (pos < l[idx1[i]]) {
                    tmp1 = l[idx1[i]] - pos;
                    np1 = l[idx1[i]];
                } else if (pos > r[idx1[i]]) {
                    tmp1 = pos - r[idx1[i]];
                    np1 = r[idx1[i]];
                }
                break;
            }
            i++;
        }
        
        int tmp2 = 0, np2 = pos;
        while (j < n) {
            if (!used[idx2[j]]) {
                if (pos < l[idx2[j]]) {
                    tmp2 = l[idx2[j]] - pos;
                    np2 = l[idx2[j]];
                } else if (pos > r[idx2[j]]) {
                    tmp2 = pos - r[idx2[j]];
                    np2 = r[idx2[j]];
                }
                break;
            }
            j++;
        }
 
        if (i == n && j == n) break;
        if (hoge == -1) {
            used[idx1[i]] = true;
            ans2 += tmp1;
            pos = np1;
            hoge = 1;
        } else {
            used[idx2[j]] = true;
            ans2 += tmp2;
            pos = np2;   
            hoge = -1;
        }
    }
    ans2 += abs(pos);
 
    cout << max(ans, ans2) << endl;
    return 0;
}