#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using testimony = pair<set<int>, set<int>>;

int main() {
    vector<int> primes;
    primes.push_back(2);
    for(int i=3; i<100010; ++i) {
        bool is_prime = true;
        for(auto p: primes) {
            if(i % p == 0) {
                is_prime = false;
                break;
            }
            if(p*p >= i) {
                break;
            }
        }
        if(is_prime) {
            primes.push_back(i);
        }
    }
    vector<int> like_nums;
    for(int i=1; i<100010; i+=2) {
        auto it = lower_bound(primes.begin(), primes.end(), i);
        if(it == primes.end() || *it != i)
            continue;
        it = lower_bound(primes.begin(), primes.end(), (i+1) / 2);
        if(it == primes.end() || *it != (i+1)/2)
            continue;
        like_nums.push_back(i);
    }

    int Q;
    int l, r;
    cin >> Q;
    rep(i, Q) {
        cin >> l >> r;
        auto il = lower_bound(like_nums.begin(), like_nums.end(), l); 
        auto ir = upper_bound(like_nums.begin(), like_nums.end(), r); 
        //cout << *il << " " << *ir << " " << ir-il << endl;
        cout << ir-il << endl;
    }

    return 0;
}

