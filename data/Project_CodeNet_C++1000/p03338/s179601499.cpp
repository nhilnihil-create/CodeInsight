#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int max = 0;
    for (int i = 1; i < n; i++) {
        vector<char> a();
        string x = s.substr(0, i);
        string y = s.substr(i);
        int count = 0;
        for (char j = 'a'; j <= 'z'; j++) {
            if (x.find(j) != string::npos && y.find(j) != string::npos) {
                count++;
            }
        }
        if (max < count) {
            max = count;
        }
    }
    cout << max << endl;
}