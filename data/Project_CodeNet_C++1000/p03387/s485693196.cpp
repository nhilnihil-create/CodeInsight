#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int diff;
    vector<int> abc(3);
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(), abc.end());

    diff = abc[2]-abc[1] + abc[2] - abc[0];
    if(diff%2) {
        cout << 1+(diff+1)/2 << endl;
    } else {
        cout << diff/2 << endl;
    }
    return 0;
}
