#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> a;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        a[input]++;
    }

    int output = 0;
    int target, count;

    for (auto num : a) {
        target = num.first;
        count = num.second;
        if (target < count) {
            output += count - target;
        } else if (target > count) {
            output += count;
        }
    }

    cout << output << endl;

    return 0;
}
