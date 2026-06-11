#include <algorithm>
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

using namespace std;
int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    bool tak = true;
    rep(i, k) {
        if(tak) {
            a = a / 2 * 2;
            b += a / 2;
            a /= 2;
        } else {
            b = b / 2 * 2;
            a += b / 2;
            b /= 2;
        }
        tak ^= 1;
    }
    cout << a << " " << b << endl;
}
