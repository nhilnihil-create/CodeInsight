#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int mid = n/10%100;

    if ( mid%11 == 0 && (mid/10 == n/1000 || mid/10 == n%10)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}