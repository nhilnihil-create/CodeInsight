#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> abc(3);
    for(int i=0;i<3;i++) {
        cin >> abc[i];
    }

    sort(abc.begin(), abc.end());
    cout << abc[2]*10+abc[1]+abc[0] << endl;
    return 0;
}
