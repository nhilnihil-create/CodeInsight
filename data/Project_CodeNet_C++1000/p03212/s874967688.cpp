#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll mx = 3*3*3*3*3*3*3*3*3*3;
string s = "753";
set<string> st;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < mx; i++) {
        int a[3] = {};
        int tmp = i;
        string ss = "";
        while (tmp > 0) {
            int k = tmp % 3;
            a[k]++;
            ss = s[k] + ss;
            tmp /= 3;
            if (ss.size() > 9) break;
            if (a[0] > 0 && a[1] > 0 && a[2] > 0) {
                if (stoi(ss) <= n) {
                    st.insert(ss);
                }
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}