#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int n;
ll t;
string s;
map<char, int> freq;

int main() {
    cin >> n >> s;
    for(int i = 0; i < s.size(); i++) {
        freq[s[i]]++;
    }
    t = 1;
    for(int i = 'a'; i <= 'z'; i++) {
        t *= (freq[i] + 1);
        t %= mod;
    }
    cout << (t - 1 + mod) % mod << endl;
}