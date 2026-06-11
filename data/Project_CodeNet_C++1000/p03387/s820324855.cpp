#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSame(vector<int> &D) {
    return (D[0] == D[1]) && (D[1] == D[2]);
}

int main() {
    vector<int> D(3);
    cin >> D[0] >> D[1] >> D[2];
    sort(D.begin(), D.end());

    int op = 0;
    while (D[1] < D[2]) {
        ++D[0];
        ++D[1];
        ++op;
    }
    if (isSame(D)) {
        cout << op << endl;
        return 0;
    }

    while (D[0] < D[1]) {
        D[0] += 2;
        ++op;
    }
    if (isSame(D)) {
        cout << op << endl;
        return 0;
    }

    // 超えたら最後に辻褄合わせ
    ++D[1];
    ++D[2];
    ++op;
    cout << op << endl;

}
