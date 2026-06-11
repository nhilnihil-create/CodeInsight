#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    vector<int> num(100001, 1);
    num[0] = 0;
    num[1] = 0;
    for (int i = 2; i <= sqrt(100000); i++) {
        if (num[i] == 1) {
            for (int j = i + i; j <= 100000; j += i) {
                num[j] = 0;
            }
        }
    }
    vector<int> mys(100001);
    for (int i = 0; i <= 100000; i++) {
        if (num[i]) {
            if (num[(i + 1) / 2]) {
                mys[i] = 1;
            }
        }
    }
    vector<int> s(100002);
    for (int i = 0; i < 100002; i++) {
        s[i + 1] = s[i] + mys[i];
    }
    int Q;
    cin >> Q;
    int l, r;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << s[r+1] - s[l] << endl;
    }
}
