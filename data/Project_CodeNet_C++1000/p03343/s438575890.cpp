#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e3+5;
int n, k, q;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1e9+9;
    for (int i = 0; i < n; i++) {
        //cout << "testing " << a[i] << '\n';
        int X = a[i];
        vector<int> v;
        vector<int> curr;
        for (int j = 0; j < n; j++) {
            if (a[j] < X) continue;
            curr.push_back(a[j]);
            if (j == n-1 || a[j+1] < X) {
                //end of contig. sequence
                /*
                for (int k: curr) {
                    cout << k << ' ';
                }
                cout << '\n';
                */
                sort(curr.begin(),curr.end());
                int rem = (int)curr.size()-k+1;
                for (int k = 0; k < rem; k++) {
                    v.push_back(curr[k]);
                }
                
                curr.clear();
            }
        }
        sort(v.begin(),v.end());
        if (v.size() >= q) {
            int Y = v[q-1];
            //cout << X << ": " << Y << '\n';
            ans = min(ans,Y-X);
        }
    }
    cout << ans << '\n';
}

