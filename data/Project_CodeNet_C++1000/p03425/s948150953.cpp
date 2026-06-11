#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200, MAXINT=2147483647;
ll b[N], t, n, mi=MAXINT;
vector<string> m, a, r, c, h;
ll M, A, R, C, H;
string s;
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        switch (s[0]) {
            case 'M': m.push_back(s); break;
            case 'A': a.push_back(s); break;
            case 'R': r.push_back(s); break;
            case 'C': c.push_back(s); break;
            case 'H': h.push_back(s); break;
            default: continue;
        }
    }
    M=m.size(); A=a.size(); R=r.size(); C=c.size(); H=h.size();
    cout << M*A*R+M*A*C+M*A*H+M*R*C+M*R*H+M*C*H+A*R*C+A*R*H+A*C*H+R*C*H;
}