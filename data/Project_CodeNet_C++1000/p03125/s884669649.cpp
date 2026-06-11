#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int, int>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORU(i, a, b, s) for(int i = a; i < b; i += s)
#define FORD(i, a, b, s) for(int i = a; i > b; i -= s)
#define endl "\n"

ll INF = 2e18;
ll MOD = 1e9 + 7;
int i, j, k;

int main() {
    int A, B;
    cin >> A >> B;
    if(B % A == 0) {
        cout << A + B << endl;
    } else {
        cout << B - A << endl;
    }
}