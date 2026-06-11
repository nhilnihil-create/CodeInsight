#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <regex>
using namespace std;

long long N, M;

bool check(long long ans) {
    long long MM = M - ans * N;
    if (MM < 0) return false;
    if (MM % ans == 0) return true;
    else return false;
}

int main() {
    cin >> N >> M;

    if (N == 1) {
        cout << M << endl;
        return 0;
    }

    for (long long ans=101010101; ans >= 1; ans--) {
        if (check(ans)) {
            cout << ans << endl;
            return 0;
        }
    }
    
    return 0;
}