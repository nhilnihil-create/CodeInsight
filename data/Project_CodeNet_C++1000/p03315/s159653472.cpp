#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 1e5 + 10;
const double eps = 1e-9;

int main() {
    int t = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        t += (s[i] == '+' ? 1 : -1);
    }
    cout << t << endl;
}