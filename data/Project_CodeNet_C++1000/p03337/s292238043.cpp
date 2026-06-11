#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;

    cin >> A >> B;

    int sum = A+B;
    int sub = A-B;
    int mult = A*B;

    priority_queue<int> ops;
    ops.push(sum);
    ops.push(sub);
    ops.push(mult);

    cout << ops.top() << endl;

    return 0;
}