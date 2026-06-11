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
    string S;
    int cnt = 0;
    cin >> S;
    if (S[0] == 'A') {
        S.erase(0, 1);
        for (int i = 1; i < S.size() - 1; i++) {
            if (S[i] == 'C') {
                cnt++;
                S.erase(i, 1);
            }
        }
        if (cnt == 1) {
            bool flag = true;
            for (int i = 0; i < S.size(); i++) {
                if (S[i] >= 'A' && S[i] <= 'Z') {
                    flag = false;
                }
            }
            if (flag) {
                AC;
                return 0;
            }
        }
    }
    WA;
}
