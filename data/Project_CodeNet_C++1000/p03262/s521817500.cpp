#include <bits/stdc++.h>
using namespace std;
#define BE(x) (x).begin(), (x).end()

int main() {
    int n, x, a;
    cin >> n >> x;

    if (n > 1000) {
        cin >> a;
        a = abs(a-x);
        vector<int> b = {1, a};
        for (int i = 2; i*i <= a; i++) {
            if (a%i == 0) {
                b.push_back(i);
                b.push_back(a/i);
            }
        }
        for (int i = 1; i < n; i++) {
            cin >> a;
            a = abs(a-x);
            int s = b.size();
            for (int j = 0; j < s; j++) {
                if (a%b[j] != 0) {
                    b.erase(b.begin()+j);
                    s--;
                }
            }
            if (s == 1) break;
        }
        cout << *max_element(BE(b)) << endl;
    }

    else {
        vector<vector<int>> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a;
            a = abs(a-x);
            int r = round(sqrt(a));
            for (int j = 1; j <= r; j++) {
                if (a%j == 0) {
                    b[i].push_back(j);
                    b[i].push_back(a/j);
                }
            }
        }
        sort (BE(b[0]));
        int s = b[0].size()-1;
        for (int i = s; i >= 0; i--) {
            int x = b[0][i];
            bool f = true;
            for (int j = 1; j < n; j++) {
                auto res = find(BE(b[j]), x);
                if (res == b[j].end()) {
                    f = false;
                    break;
                }
            }
            if (f) {
                cout << x << endl;
                return 0;
            }
        }
    }
    
}