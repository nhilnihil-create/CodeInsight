#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> L(n);
    for(int i=0; i<n; i++) cin >> L[i];

    sort(L.begin(), L.end());
    int max_L = L[n-1];
    int total_L = 0;

    for(int i=0; i<n-1; i++ ) total_L += L[i];

    if(total_L > max_L) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

