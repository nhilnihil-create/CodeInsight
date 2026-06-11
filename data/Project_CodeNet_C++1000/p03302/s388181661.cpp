#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define sz(x) (int)(x).size()
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a * b == 15)
        cout << "*" << endl;
    else if (a + b == 15)
        cout << "+" << endl;
    else
        cout << "x" << endl;
    return 0;
}