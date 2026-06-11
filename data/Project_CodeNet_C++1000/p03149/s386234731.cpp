#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> st = {1, 7, 9, 4};
    for (int i = 0; i < 4; ++i) {
        int a;
        cin >> a;
        if (st.find(a) != st.end()) st.erase(a);
    }

    if (st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
