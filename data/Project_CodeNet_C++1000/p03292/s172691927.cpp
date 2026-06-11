#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, s, e) for (int i = (int)(s); i < (int)(e); i++)
#define _rep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define _REP(i, e, s) for (int i = (int)(e - 1); i >= (int)(s); i--)

#define yes cout << "yes" << endl;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;

#define no cout << "no" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;

#define out(s) cout << s << endl;

#define ll long long
#define ull unsigned long long
#define vi vector<int>

const double PI = 3.14159265358979323846;

int main() {
    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    cout << max({A1, A2, A3}) - min({A1, A2, A3}) << endl;
}
