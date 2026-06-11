#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N); 
    for (int i = 0; i < N; ++i) cin >> A[i];

    // 操作回数
    int counter = 0;

    // 操作が行えなくなるまで操作を行う
    while (true) {
        // 操作が行えるかどうかを判定する
        bool can_do = true;
        for (int i = 0; i < N; ++i) {
            if (A[i] % 2 == 1) can_do = false;
        }

        // 操作を行えないならば、ループを打ち切る
        if (!can_do) break;

        // 操作を行えるならば、操作を行う
        for (int i = 0; i < N; ++i) {
            A[i] /= 2; // 2 で割る
        }

        // 操作回数をカウントする
        ++counter;
    }
    cout << counter << endl;
}