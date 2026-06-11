#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,max=0,flag,sum=0;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l.at(i);

    }
    for (int i = 0; i < n; i++) {
        if (max < l.at(i)) {
            max = l.at(i);
            flag = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != flag) {
            sum += l.at(i);
        }
    }
    if (sum > max) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}