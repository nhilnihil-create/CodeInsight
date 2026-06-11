#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;
typedef long long ll;

int main() {
    int Q;
    cin >> Q;
    vector<vector<int>> data(Q, vector<int>(2));
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> data.at(i).at(j);
        }
    }
    int MAX = 100001;
    vector<int> bit(MAX + 1,0);
    for (int i = 2; i * i <= MAX; i++) {
        if (bit.at(i) != 0) {
            continue;
        }
        for (int j = i * 2; j <= MAX; j += i) {
            bit.at(j)++;
        }
    }
    vector<int> judge(MAX + 1, 0);
    for (int i = 3; i < MAX + 1; i++) {
        if (bit.at(i) == 0 && bit.at((i + 1) / 2) == 0) {
            judge.at(i)++;
        }
    }
    vector<int> rsum(MAX + 1, 0);
    int sum = 0;
    for (int i = 1; i < MAX + 1; i++) {
        sum += judge.at(i);
        rsum.at(i) = sum;
    }
    int ans;
    for (int i = 0; i < Q; i++) {
        ans = rsum.at(data.at(i).at(1)) - rsum.at(data.at(i).at(0) - 1);
        cout << ans << endl;
    }
}