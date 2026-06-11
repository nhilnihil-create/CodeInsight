#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

int mxN = 50000000;
vector<int> cnt(mxN + 1);

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    k--;
    s[k] = tolower(s[k]);
    cout << s;

    return 0;
}