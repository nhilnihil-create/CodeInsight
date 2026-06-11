#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> res;
    for(int i = n-1; i >= 0; i--) {
        int idx = -1;
        for(int k = 0; k < A.size(); k++) {
            if(A[k] == k) {
                idx = k;
            }
        }
        if(idx == -1) {
            cout << -1 << endl;
            return 0;
        }
        res.push_back(idx+1);
        A.erase(A.begin()+idx);
    }
    reverse(res.begin(), res.end());
    for(int x : res) cout << x << "\n";
    return 0;
}

