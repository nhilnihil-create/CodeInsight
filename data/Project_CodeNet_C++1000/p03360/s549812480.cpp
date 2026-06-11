#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3);
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int target = a[2];
    int k;
    cin >> k;
    int sum = a[0] + a[1] + a[2] * pow(2,k);
    cout << sum;
}