#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;

    vector<int> a_n;
    a_n.push_back(s);

    while (true) {
        int cur = a_n.back(), next;
        if (cur % 2 == 0)
            next = cur / 2;
        else
            next = 3 * cur + 1;
        
        for (int i = 0, n = a_n.size(); i < n; i++)
            if (a_n.at(i) == next) {
                cout << n + 1 << endl;
                return 0;
            }

        a_n.push_back(next);
    }
}