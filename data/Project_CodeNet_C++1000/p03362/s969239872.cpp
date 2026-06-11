#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n;
bool is_prime[55559];
vector<llong> ans;

int main() {
    fill(is_prime, is_prime + sizeof(is_prime) / sizeof(bool), true);
    cin >> n;

    is_prime[0] = is_prime[1] = false;
    for (llong i = 2; i * i <= 55555; i++) {
        if (is_prime[i]) {
            for (llong j = i + i; j <= 55555; j += i) is_prime[j] = false;
        }
    }

    llong i = 1;
    while (ans.size() < n) {
        if (is_prime[i]) {
            ans.push_back(i);
        }
        i += 5;
    }

    for (auto a:ans) {
        cout << a << ' ';
    }
    cout << endl;
    
    return 0;
}
