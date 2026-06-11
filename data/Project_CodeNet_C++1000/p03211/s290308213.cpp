#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int keta(long long S) {
    int ans = 1;
    while (true) {
        if (S < 10) {
            break;
        }
        ans++;
        S = floor(S / 10);
    }
    return ans;
}

int sub(int a, int b) {
    int ans;
    if (a < b) {
        ans = b - a;
        return ans;
    }
    ans = a - b;
    return ans;
}

int main() {
    long long S;
    cin >> S;
    vector<long long> data(keta(S));
    long long num;
    int N = keta(S);
    for (int i = N - 1; 0 <= i; i--) {
        num = S % 10;
        data.at(i) = num;
        S = floor(S / 10);
    }
    int sum, ansa;
    int ans = sub(data.at(0) * 100 + data.at(1) * 10 + data.at(2), 753);
    for (int i = 1; i < N - 2; i++) {
        sum = sub(data.at(i) * 100 + data.at(i + 1) * 10 + data.at(i + 2), 753);
        ans = min(ans, sum);
    }
    cout << ans << endl;
}