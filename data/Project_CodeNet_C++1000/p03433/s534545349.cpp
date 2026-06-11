#include <bits/stdc++.h>
using namespace std;

int main() {
    int spending, haveCoins;
    cin >> spending >> haveCoins;

    int justSpending = spending % 500;

    if (justSpending == 0) {
        cout << "Yes" << endl;
    } else if ((justSpending - haveCoins) <= 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}