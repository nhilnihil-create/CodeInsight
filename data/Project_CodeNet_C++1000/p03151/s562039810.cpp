#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long sum_A = 0, sum_B = 0;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        sum_A += a;
        A.at(i) = a;
    }
    for (int i = 0; i < N; i++) {
        long long b;
        cin >> b;
        sum_B += b;
        B.at(i) = b;
    }

    long long keep = 0, count = 0;
    bool alr = true;
    vector<long long> data;
    if (sum_A < sum_B) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        keep += A.at(i) - B.at(i);
        if (A.at(i) - B.at(i) < 0) {
            alr = false;
            count++;
        }
        else {
            data.push_back(A.at(i) - B.at(i));
        }
    }

    if (alr) {
        cout << 0 << endl;
        return 0;
    }
    sort(data.begin(), data.end());
    while (data.size() != 0) {
        keep -= data.at(0);
        if (keep >= 0) {
            data.erase(data.begin());
        }
        else {
            break;
        }
    }

    cout << data.size() + count << endl;
    return 0;
}