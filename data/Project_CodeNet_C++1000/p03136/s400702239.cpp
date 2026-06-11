#include<iostream>
using namespace std;

int main() {
    int n, l;
    cin >> n;

    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> l;
        sum += l;
        maxi = max(l, maxi);
    }

    if (sum - maxi > maxi) cout << "Yes" << endl;
    else cout << "No" << endl;
}