#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll yo[12345678], ta[12345678];
signed main() {
    ll n, m, t = 0, yoko = 0, tate = 0; string s; cin >> s >> n >> m;
    queue<ll> queyoko, quetate; quetate.push(0);
    if (s[s.size() - 1] == 'F') { s.push_back('T'); }
    for (int h = 0; h < s.size(); h++) {
        if (s[h] == 'F') {
            if (t % 2 == 0) { yoko++; }
            else { tate++; }
        }
        else {
            if (t == 0) { queyoko.push(yoko); yoko = 0; }
            else if (t % 2 == 1) {
                ll z = quetate.size(); map<ll, ll> ima;
                for (int h = 0; h < z; h++) {
                    if (ima[quetate.front() + tate] == 0) {
                        quetate.push(quetate.front() + tate);
                        ima[quetate.front() + tate]++;
                    }
                    if (ima[quetate.front() - tate] == 0) {
                        quetate.push(quetate.front() - tate);
                        ima[quetate.front() - tate]++;
                    }
                    quetate.pop();
                }
                tate = 0;
            }
            else {
                ll z = queyoko.size(); map<ll, ll> ima;
                for (int h = 0; h < z; h++) {
                    if (ima[queyoko.front() + yoko] == 0) {
                        queyoko.push(queyoko.front() + yoko);
                        ima[queyoko.front() + yoko]++;
                    }
                    if (ima[queyoko.front() - yoko] == 0) {
                        queyoko.push(queyoko.front() - yoko);
                        ima[queyoko.front() - yoko]++;
                    }
                    queyoko.pop();
                }
                yoko = 0;
            }
            t++;
        }
    }
    ll z = 0;
    while (!queyoko.empty()) {
        //cout << queyoko.front() << endl;
        if (queyoko.front() == n) { z++; break; }
        queyoko.pop();
    }
    while (!quetate.empty()) {
        //cout << ' ' << quetate.front() << endl;
        if (quetate.front() == m) { z++; break; }
        quetate.pop();
    }
    if (z == 2) { cout << "Yes" << endl; }
    else { cout << "No" << endl; }
    return 0;
}