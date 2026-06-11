#include <iostream>
#include <vector>
#include <string>
#define x first
#define y second

using namespace std;

int check_elimination(int n, int q, int idx, string &s, vector <pair <char, char> > &st) {
    int curr_pos = idx, curr_char = s[idx];
    for (auto &&spell: st) {
        if (spell.x == curr_char) {
            if (spell.y == 'L') {
                curr_pos--;
                if (curr_pos == -1)
                    return 1;
            }
            else {
                curr_pos++;
                if (curr_pos == n)
                    return 2;
            }
            curr_char = s[curr_pos];
        }
    }
    return 0;
}

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector <pair <char, char> > st(q);
    for (int i = 0; i < q; i++) {
        cin >> st[i].x >> st[i].y;
    }

    int rightmost = -1, leftmost = n, left = 0, right = n - 1, middle;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (check_elimination(n, q, middle, s, st) == 1) {
            rightmost = middle;
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    left = 0; 
    right = n - 1;

    while (left <= right) {
        middle = left + (right - left) / 2;
        if (check_elimination(n, q, middle, s, st) == 2) {
            leftmost = middle;
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    cout << n - (rightmost + 1 + n - leftmost) << '\n';
    return 0;
}