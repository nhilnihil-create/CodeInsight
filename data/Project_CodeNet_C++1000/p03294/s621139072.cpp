#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> V(n);
    for(int i=0; i<n; i++) cin >> V[i];
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += V[i] - 1;
    }
    cout << sum << endl;
}