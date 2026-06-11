#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a[5],k;
    for(int i=0;i<5;i++) {
        cin >> a[i];
    }
    cin >> k;

    if((a[4]-a[0]) > k) {
        cout << ":(\n";
    } else {
        cout << "Yay!\n";
    }

    return 0;
}
