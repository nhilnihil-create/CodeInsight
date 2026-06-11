#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <iomanip>
#include <iterator>

#define MOD 1000000007
#define INF 1000000001

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


template <class T>
ostream &operator<<(ostream &o, const vector<T>&obj) {
    o << "["; for (int i = 0; i < (int)obj.size(); ++i) o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U>&obj) {
    o << "(" << obj.first << ", " << obj.second << ")"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const map<T, U>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const set<T>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const queue<T>&obj) {
    queue<T> obj_cp = obj;
    bool first = true;
    o << "{";
    while (!obj_cp.empty()) { o << (!first ? ", " : "") << obj_cp.front(); obj_cp.pop(); first = false; }
    o << "}"; return o;
}

void print() {
    cout << "\n";
}
template<class Head, class... Body>
void print(Head head, Body... body) {
    cout << head << " ";
    print(body...);
}


vector<int> get_primes(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[2] = true;
    for (int i = 2; i * i <= n; ++i) {
        if (!is_prime[i]) continue;
        for (int j = 2; i*j <= n; ++j) {
            is_prime[i*j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}


int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<int> primes = get_primes(N);
    // print(primes);
    map<int, int> p_count;
    for (int i = 0; i < primes.size(); ++i) {
        p_count[primes[i]] = 0;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < primes.size(); ++j) {
            int c = 0;
            int i_ = i;
            while (i_ % primes[j] == 0) {
                i_ /= primes[j];
                c += 1;
            }
            p_count[primes[j]] += c;
        }
        // print(i, p_count);
    }

    int ans = 0;
    for (int p : primes) {
        if (p_count[p] >= 74) {
            ans += 1;
            // print(p);
        }
        for (int q : primes) {
            if (q <= p) continue;  // p < q
            if (p_count[p] >= 2 && p_count[q] >= 24) ans += 1;
            if (p_count[q] >= 2 && p_count[p] >= 24) ans += 1;
            if (p_count[p] >= 4 && p_count[q] >= 14) ans += 1;
            if (p_count[q] >= 4 && p_count[p] >= 14) ans += 1;
            for (int r : primes) {
                if (r <= q) continue;  // p < q < r
                if (p_count[p] >= 2 && p_count[q] >= 4 && p_count[r] >= 4) ans += 1;
                if (p_count[q] >= 2 && p_count[p] >= 4 && p_count[r] >= 4) ans += 1;
                if (p_count[r] >= 2 && p_count[p] >= 4 && p_count[q] >= 4) ans += 1;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
