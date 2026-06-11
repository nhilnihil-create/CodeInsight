#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int N;
    long x;
    cin >> N;
    cin >> x;
    vector<long> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
    }
    sort(data.begin(), data.end());
    long sum = data.at(0);
    int ans = 0;
    for (int i = 1; i < N + 1; i++) {
        if (x < sum) {
            break;
        }
        if (sum == x) {
            ans++;
            break;
        }
        ans++;
        if (i == N) {
            break;
        }
        sum += data.at(i);
    }
    if (ans == N && sum < x) {
        ans--;
    }
    cout << ans << endl;
}