#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string string_X = "";
    string string_Y = s;
    int biggest = 0;
    for (int i = 0; i < n; i++) {
        //remove first
        string_Y = string_Y.substr(1, string_Y.size() - 1);
        //add next
        string_X += s[i];
        //conv to sets
        set<char> set_x = set<char>(string_X.begin(), string_X.end());
        set<char> set_y = set<char>(string_Y.begin(), string_Y.end());
        int overlap = 0;
        for (auto i : set_x) {
            if (set_y.find(i) != set_y.end()) {
                overlap++;
            }
        }
        biggest = max(biggest, overlap);
    }
    cout << biggest;
}