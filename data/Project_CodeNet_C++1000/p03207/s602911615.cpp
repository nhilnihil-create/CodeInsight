#include<iostream>
using namespace std;

int main() {
    int n, p;
    cin >> n;

    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p;
        sum += p;
        maxi = max(p, maxi);
    }

    cout << sum - maxi / 2 << endl;
}