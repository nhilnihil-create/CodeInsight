#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    ll N;
    cin >> N;
    ll i = 0;
    while((i + 1)*(i + 1) <= N) {
        i++;
    }
    cout << i*i << endl;
}

