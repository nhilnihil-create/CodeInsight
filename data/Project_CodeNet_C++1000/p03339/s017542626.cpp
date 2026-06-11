#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int count = n;
    vector<int> lefts(n + 1);
    vector<int> rights(n + 1);
    
    if (s.at(0) == 'W') lefts.at(0) = 1;
    for (int i = 1; i < n; i++) {
        lefts.at(i) = lefts.at(i - 1);
        if (s.at(i) == 'W') lefts.at(i)++;
    }

    for (int i = n - 1; i >= 0; i--) {
        rights.at(i) = rights.at(i + 1);
        if (s.at(i) == 'E') rights.at(i)++;
    }
    count = min(rights.at(1), count);
    for (int i = 1; i < n; i++) {
        count = min(lefts.at(i - 1) + rights.at(i + 1), count);
    }
    cout << count << endl;

return 0;
}