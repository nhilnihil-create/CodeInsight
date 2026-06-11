#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
char b;


void input() {
    cin >> b;
}


int main() {
    input();
    map<char, char> m;
    m['A'] = 'T';
    m['T'] = 'A';
    m['C'] = 'G';
    m['G'] = 'C';
    char ans = m[b];
    cout << ans << endl;
}
