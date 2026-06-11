#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string said_before[n], last_string, curr_string;
    cin >> last_string;
    for (int i = 0; i < n - 1; i++) {
        said_before[i] = last_string;
        cin >> curr_string;
        if (last_string[last_string.length() - 1] != curr_string[0]) {
            cout << "No";
            return 0;
        }
        for (int j = i; j >= 0; j--) {
            if (curr_string == said_before[j]) {
                cout << "No";
                return 0;
            }
        }
        last_string = curr_string;
    }
    cout << "Yes";
    return 0;
}

