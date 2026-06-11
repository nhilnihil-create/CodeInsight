#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    string str; cin >> str;
    ll A = stoi(str) / 1000;
    ll B = stoi(str) / 100 % 10;
    ll C = stoi(str) / 10 % 10;
    ll D = stoi(str) % 10;
    vector<char> op1 = { '+', '-', '+', '-', '-', '+', '+', '-' };
    vector<char> op2 = { '+', '-', '-', '+', '-', '+', '-', '+' };
    vector<char> op3 = { '+', '-', '+', '-', '+', '-', '-', '+' };

    rep(i, 8) {
        if (op1[i] == '+') {
            if (op2[i] == '+') {
                if (op3[i] == '+') {
                    if (A + B + C + D == 7) {
                        cout << A << '+' << B << '+' << C << '+' << D << '=' << '7' << endl;
                        return 0;
                    }
                } else {
                    if (A + B + C - D == 7) {
                        cout << A << '+' << B << '+' << C << '-' << D << '=' << '7' << endl;
                        return 0;
                    }
                }
            } else {
                if (op3[i] == '+') {
                    if (A + B - C + D == 7) {
                        cout << A << '+' << B << '-' << C << '+' << D << '=' << '7' << endl;
                        return 0;
                    }
                } else {
                    if (A + B - C - D == 7) {
                        cout << A << '+' << B << '-' << C << '-' << D << '=' << '7' << endl;
                        return 0;
                    }
                }
            }
        } else  {
            if (op2[i] == '+') {
                if (op3[i] == '+') {
                    if (A - B + C + D == 7) {
                        cout << A << '-' << B << '+' << C << '+' << D << '=' << '7' << endl;
                        return 0;
                    }
                } else {
                    if (A - B + C - D == 7) {
                        cout << A << '-' << B << '+' << C << '-' << D << '=' << '7' << endl;
                        return 0;
                    }
                }
            } else {
                if (op3[i] == '+') {
                    if (A - B - C + D == 7) {
                        cout << A << '-' << B << '-' << C << '+' << D << '=' << '7' << endl;
                        return 0;
                    }
                } else {
                    if (A - B - C - D == 7) {
                        cout << A << '-' << B << '-' << C << '-' << D << '=' << '7' << endl;
                        return 0;
                    }
                }
            }
        }
    }
}