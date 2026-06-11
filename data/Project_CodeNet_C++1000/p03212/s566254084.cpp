#include "bits/stdc++.h"

using namespace std;

bool is753(long long n) {
    string n_str = to_string(n);
    bool ret = (n_str.find('3') != n_str.npos);
    ret &= (n_str.find('5') != n_str.npos);
    ret &= (n_str.find('7') != n_str.npos);
    return ret;
}

long long count753(long long N) {
    vector<long long> candidates({ 33LL, 35LL, 37LL, 53LL, 55LL, 57LL, 73LL, 75LL, 77LL });
    long long pow10 = 100LL;
    long long ans = 0LL;
    for (long long d = 3; d < 11; ++d) {
        vector<long long> nextCandidate;
        for (long long i = 0; i < 3; ++i) {
            long long toAdd = (3LL + 2LL * i) * pow10;
            for (long long j = 0; j < candidates.size(); ++j) {
                long long x = toAdd + candidates[j];
                if (x > N) {
                    return ans;
                }
                nextCandidate.push_back(x);
                if (is753(x)) {
                    ++ans;
                }
            }
        }
        candidates = nextCandidate;
        pow10 *= 10LL;
    }
}

void Main() {
    long long N;
    cin >> N;
    cout << count753(N) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
