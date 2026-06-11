#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    unsigned long num = 0;
    unsigned long pre_num = 1;
    unsigned long pre_pre_num = 2;

    if (N == 1) {
        num = 1;
    } else {
        for (int i = 0; i < (N-1); i++) {
            num = pre_num + pre_pre_num;
            pre_pre_num = pre_num;
            pre_num = num;
        }
    }

    cout << num << endl;
}