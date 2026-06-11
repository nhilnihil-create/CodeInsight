#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define isz(x) (int)(x).size()
#define watch(x) std::cerr << #x << " = " << x
#define watchsp(x) watch(x) << ' '
#define watchln(x) watch(x) << std::endl
#define cerr cerr && debug && std::cerr
using ll = long long;
using vi = std::vector<int>;
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    for (int i = 0; i < isz(vec); i++) {
        if (i > 0) os << ", ";
        os << vec[i];
    } 
    return os << "}";
}
const int mod = (int)1e9+7, debug = 0;
int fast(int n, std::string s) {
    vi curr(1+n+1), prev(1+n+1);
    curr[1] = 1;
    for (int i = n-2; i >= 0; i--) {
        watchln(curr);
        int min = 1, max = n-i;
        if (s[i] == '<') {
            int sum = 0;
            for (int t = max; t >= min; t--) {
                sum += curr[t];
                if (sum >= mod) sum -= mod;
                if (t == max) {
                    prev[t] = 0;
                } else {
                    prev[t] = sum;
                }
            }
        } else { // prev > curr
            int sum = 0;
            for (int t = min; t <= max; t++) {
                if (t == min) {
                    prev[t] = 0;
                } else {
                    prev[t] = sum;
                }
                sum += curr[t];
                if (sum >= mod) sum -= mod;
            }
        }
        curr = prev;
    }
    watchln(curr);
    return int(std::accumulate(all(curr), ll(0)) % mod);
}
int slow(int n, std::string s) {
    vi p(n);
    for (int i = 1; i <= n; i++) {
        p[i-1] = i;
    }
    int answ = 0;
    do {
        bool ok = true;
        for (int i = 0; i + 1 < n; i++) {
            ok &= (s[i] == '>' && p[i] > p[i+1]) || (s[i] == '<' && p[i] < p[i+1]);
        }
        answ += ok;
    } while (std::next_permutation(all(p)));
    return answ;
}
void test() {
    for (int n = 2; n <= 8; n++) {
        std::string s(n-1,'>');
        for (int mask = 0; mask < (1 << (n-1)); mask++) {
            for (int bit = 0; bit < n-1; bit++) {
                s[bit] = (mask & (1 << bit)) ? '<' : '>';
            }
            if (fast(n,s) != slow(n,s)) {
                std::cout << "n = " << n << ", s = " << s << std::endl;
                std::cout << "fast = " << fast(n,s) << std::endl;
                std::cout << "slow = " << slow(n,s) << std::endl;
                std::exit(0);
            }
        }
    }
    std::exit(0);
}
int main() {
    //test();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n; std::cin >> n; std::string s;
    std::cin >> s;
    std::cout << fast(n, s) << std::endl;
    return 0;
}