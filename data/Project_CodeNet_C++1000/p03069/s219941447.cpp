#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    // int output = 0;
    // int before = 1;
    // while (before != output) {
    // int index = 0;
    // before = output;

    // while (index < N) {
    // int b = 0, w = 0;
    // while (S[index] == '#') {
    // b++;
    // index++;
    // }
    // while (S[index] == '.') {
    // w++;
    // index++;
    // }
    // output += min(b, w);
    // }
    // }

    vector<int> b_acc(N + 1, 0);
    vector<int> w_acc(N + 1, 0);

    int b = 0, w = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '#') {
            b++;
        } else {
            w++;
        }
        b_acc[i + 1] = b;
        w_acc[N - i - 1] = w;
    }
    vector<int> w_tmp = w_acc;
    for (int i = 0; i < N; i++) {
        w_acc[N - i] = w - w_tmp[i];
    }

    int output = N;
    for (int i = 0; i < N + 1; i++) {
        output = min(output, b_acc[i] + w_acc[i]);
    }

    cout << output << endl;

    return 0;
}
