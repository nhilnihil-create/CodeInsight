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
    int A, B; cin >> A >> B;
    if (A >= 13) {
        cout << B;
    } else if (A >= 6) {
        cout << B/2;
    } else {
        cout << 0;
    }
}