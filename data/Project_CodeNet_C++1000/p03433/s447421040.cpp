#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A;
    cin >> N >> A;

    int remain = N % 500;

    string res = "No";
    if (remain <= A) {
        res = "Yes";
    }

    cout << res << endl;
    return 0;
}