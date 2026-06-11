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

#define AC cout << "AC" << endl;
#define WA cout << "WA" << endl;

#define out(s) cout << s << endl;

#define ll long long
#define ull unsigned long long
#define vi vector<int>

const double PI = 3.14159265358979323846;

int main() {
    int A, B, K;
    vector<int> v;
    cin >> A >> B >> K;
    REP(i, 1, max(A + 1, B + 1)) {
        // cout << i << endl;
        if (A % i == 0 && B % i == 0) {
            v.push_back(i);
        }
    }
    cout << v[v.size() - K] << endl;
}