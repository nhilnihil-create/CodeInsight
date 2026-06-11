#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N;
    cin >> N;
    map<char, long long> initial;
    initial.insert(make_pair('M', 0));
    initial.insert(make_pair('A', 0));
    initial.insert(make_pair('R', 0));
    initial.insert(make_pair('C', 0));
    initial.insert(make_pair('H', 0));
    for (long long i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (s[0] == 'M') {
            initial['M'] += 1;
        }
        else if (s[0] == 'A') {
            initial['A'] += 1;
        }
        else if (s[0] == 'R') {
            initial['R'] += 1;
        }
        else if (s[0] == 'C') {
            initial['C'] += 1;
        }
        else if (s[0] == 'H') {
            initial['H'] += 1;
        }
    }

    long long ans = 0;
    ans += initial['M'] * initial['A'] * initial['R'];
    ans += initial['M'] * initial['A'] * initial['C'];
    ans += initial['M'] * initial['A'] * initial['H'];
    ans += initial['M'] * initial['R'] * initial['C'];
    ans += initial['M'] * initial['R'] * initial['H'];
    ans += initial['M'] * initial['C'] * initial['H'];
    ans += initial['A'] * initial['R'] * initial['C'];
    ans += initial['A'] * initial['R'] * initial['H'];
    ans += initial['A'] * initial['C'] * initial['H'];
    ans += initial['R'] * initial['C'] * initial['H'];
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
