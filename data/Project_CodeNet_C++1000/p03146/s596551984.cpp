#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;
    vector<int> v = {s};

    for(int i=2;;i++) {
        if(s % 2 == 0) {
            s /= 2;
        }
        else if(s % 2 == 1) {
            s = s*3 + 1;
        }

        auto result = find(v.begin(), v.end(), s);
        if(result != v.end()) {
            cout << i << endl;
            return 0;
        }
        v.push_back(s);
    }
}

