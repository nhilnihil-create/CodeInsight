#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    string s;
    cin >> s;
    vector<size_t> east(n + 1, 0);
    vector<size_t> west(n + 1, 0);
    size_t e = 0;
    size_t w = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 'E') ++e;
        else ++w;
        east[i + 1] = e;
        west[i + 1] = w;
    }
    size_t num_turn = n;
    for (size_t i = 0; i < n; ++i) {
        size_t turn = west[i] + east[n] - east[i + 1];
        if (turn < num_turn) num_turn = turn;
    }
    cout << num_turn << endl;
    return EXIT_SUCCESS;
}