#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;cin>>N;
    vector<bool> flg;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (N != 1) {
        if (N < 0 && N % 2 != 0) {
            N = N / (-2) + 1;
            flg.push_back(true);
        } else {
            if (N % 2 == 0) flg.push_back(false);
            else flg.push_back(true);
            N /= -2;
        }
    }
    flg.push_back(true);
    reverse(flg.begin(), flg.end());
    for (int i = 0; i < flg.size(); i++) {
        if (flg.at(i)) cout << 1;
        else cout << 0;
    }
    cout << endl;
    return 0;
}