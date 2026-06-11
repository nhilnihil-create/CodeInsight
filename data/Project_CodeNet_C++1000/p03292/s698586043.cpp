#include <bits/stdc++.h>
using namespace std;

int main() {
    int A1, A2, A3, minimum, maximum;
    cin >> A1 >> A2 >> A3;
    // 最小値を求める
    minimum = min(min(A1, A2), A3);
    maximum = max(max(A1, A2), A3);
    cout << maximum - minimum << endl;
    return 0;
}