#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

long sumn(long n) {
    long ans = 0;
    for (long i = 0; i <= n; i++) {
        ans += i;
    }
    return ans;
}

int main() {
    string S;
    cin >> S;
    long sum = 0;
    long ido = 0;
    for (long i = 0; i < S.size(); i++) {
        if (S.at(i) == 'W') {
            sum++;
            ido += i + 1;
        }
    }
    long ans = ido - sumn(sum);
    cout << ans << endl;
}