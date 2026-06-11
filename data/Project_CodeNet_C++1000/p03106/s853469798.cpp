#include <iostream>
#include <string>
#include <vector>

#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> mods;
    for (int i = 1; i <= 100; i++) {
        if (a % i == 0 && b % i == 0)
            mods.push_back(i);
    }

    cout << mods.at(mods.size() - k) << endl;
}

