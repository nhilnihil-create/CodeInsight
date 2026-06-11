#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> data(M);
    for (int i = 0; i < M; i++) {
        cin >> data.at(i);
    }
    int sum0 = 0;
    int sumN = 0;
    for (int x : data) {
        if (x < X) {
            sum0++;
        }
        else {
            sumN++;
        }
    }
    int ans = min(sum0, sumN);
    cout << ans << endl;
}