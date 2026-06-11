#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define f cin
#define NMAX 200010
using namespace std;

//ifstream f("date.in");

int n, m;
string s;
char move_char[NMAX], move_type[NMAX];

int right_most, left_most;

bool left_match(int x) {
    int current_pos = x;
    char current_character = s[x];
    for (int i = 0; i < m; ++i) {
        if (current_character  == move_char[i]) {
            if (move_type[i] == 'L') {
                current_pos --;
            } else {
                current_pos ++;
            }
            if (current_pos < 0) return true;
            if (current_pos >= n) return false;
            current_character = s[current_pos];
        }
    }
    return false;
}

bool right_match(int x) {
    int current_pos = x;
    char current_character = s[x];
    for (int i = 0; i < m; ++i) {
        if (current_character  == move_char[i]) {
            if (move_type[i] == 'L') {
                current_pos --;
            } else {
                current_pos ++;
            }
            if (current_pos < 0) return false;
            if (current_pos >= n) return true;
            current_character = s[current_pos];
        }
    }
    return false;
}


void find_right_most(int st, int dr) {
    if (st > dr) return;
    if (st == dr) {
        if (left_match(st)) {
            right_most = max(right_most, st);
        }
        return;
    }
    int mij = (st + dr) / 2;
    if (left_match(mij)) {
        right_most = max(right_most, mij);
        find_right_most(mij + 1, dr);
    } else {
        find_right_most(st, mij - 1);
    }
}

void find_left_most(int st, int dr) {
    if (st > dr) return;
    if (st == dr) {
        if (right_match(st)) {
            left_most = min(left_most, st);
        }
        return;
    }
    int mij = (st + dr) / 2;
    if (right_match(mij)) {
        left_most = min(left_most, mij);
        find_left_most(st, mij - 1);
    } else {
        find_left_most(mij + 1, dr);
    }
}


void solve() {

    right_most = -1;
    left_most = n;
    find_right_most(0, n);
    find_left_most(0, n);

    int total_sum = right_most + 1 + n - left_most;
    if (left_most < right_most) {
        total_sum -= (right_most - left_most + 1);
    }
    cout << n - total_sum;
}

int main() {

    f >> n >> m;
    f >> s;
    for (int i = 0; i < m; ++i) {
        f >> move_char[i] >> move_type[i];
    }

    solve();

    return 0;
}
