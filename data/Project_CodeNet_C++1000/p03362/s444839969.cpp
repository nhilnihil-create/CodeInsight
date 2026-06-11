#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using pii = pair<int, int>;

const int MAX_NUM = 55555; // 55555 以下の素数の数は5637

int main() {
    vector<int> prime, prime5p1;
    bool p[MAX_NUM + 1];
    rep(i, MAX_NUM) p[i] = true;
    p[0] = false;
    p[1] = false;
    rep(i, MAX_NUM) {
        if (p[i] == true) {
            prime.push_back(i);
            for (int j=i+i; j<MAX_NUM; j+=i) p[j] = false;
        }
    }
    for (auto k : prime) if (k%5 == 1) prime5p1.push_back(k);

    int N;
    cin >> N;
    for (auto k : prime5p1) {
        if (N == 0) break;
        cout << k << " ";
        N--;
    }

    cout << endl;

    return 0;
}

 