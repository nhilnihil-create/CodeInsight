#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
    }
    int ans = X;
    for (int x : data) {
        ans += floor(D / x) + 1;
        if (D % x == 0) {
            ans--;
        }
    }
    cout << ans << endl;
}