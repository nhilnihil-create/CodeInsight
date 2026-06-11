#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAX 1000000000
vector<ll> vec;
void dfs(ll x) {
    ll a1 = x * 10 + 3;
    ll a2 = x * 10 + 5;
    ll a3 = x * 10 + 7;
    if (a1 < MAX) {
        vec.push_back(a1);
        dfs(a1);
    }
    if (a2 < MAX) {
        vec.push_back(a2);
        dfs(a2);
    }
    if (a3 < MAX) {
        vec.push_back(a3);
        dfs(a3);
    }
}
bool check(ll a) {
    bool thr = false;
    bool fiv = false;
    bool sev = false;
    while (a) {
        if (a % 10 == 3) {
            thr = true;
        }
        else if (a % 10 == 5) {
            fiv = true;
        }
        else {
            sev = true;
        }
        a /= 10;
    }
    return thr && fiv && sev;
}
int main () {
    int n;
    cin >> n;
    int count = 0;
    dfs(0);
    for (int i = 0; i < vec.size(); i++) {
        if ((n >= vec[i])&&(check(vec[i]))) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}