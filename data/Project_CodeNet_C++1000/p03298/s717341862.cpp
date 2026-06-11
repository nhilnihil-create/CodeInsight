#include <iostream>
#include <string>
#include <map>

#define p pair<string, string>
#define ll long long
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    map<string, ll> front;
    for (int i = 0; i < 1 << n; i++) {
        string a, b;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) a = a + s[j];
            else b = s[j] + b;
        }
        front[a + "-" + b]++;
    }
    map<string, ll> back;
    for (int i = 0; i < 1 << n; i++) {
        string a, b;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) a = a + s[n + j];
            else b = s[n + j] + b;
        }
        back[b + "-" + a]++;
    }

    ll ret = 0;
    for (auto x:front) ret += x.second * back[x.first];

    cout << ret << endl;
    return 0;
}