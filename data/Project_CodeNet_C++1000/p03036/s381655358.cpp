#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;


int main() {
    int r, D, x_2000; cin >> r >> D >> x_2000;
    int x_now, x_old = x_2000;

    for (int i = 0; i < 10; i++) {
        x_now = r*x_old - D;
        x_old = x_now;
        cout << x_now << endl;
    }
}