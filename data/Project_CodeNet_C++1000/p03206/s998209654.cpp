#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(it) it.begin(), it.end()
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORU(i, a, b, s) for(int i = a; i < b; i += s)
#define FORD(i, a, b, s) for(int i = a; i > b; i -= s)
#define endl "\n"

ll INF = 2e18;
ll MOD = 1e9 + 7;
int i, j, k, t;

int main() {
    int D;
    cin >> D;

    if(D == 22) {
        cout << "Christmas Eve Eve Eve" << endl;
    } else if(D == 23) {
        cout << "Christmas Eve Eve" << endl;
    } else if(D == 24) {
        cout << "Christmas Eve" << endl;
    } else if(D == 25) {
        cout << "Christmas" << endl;
    }
}