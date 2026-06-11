#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 0; i <= n - 1; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    for (int i = 0; i <= n - 1; i++) {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    //printVector(v1);
    //printVector(v2);
    int tot = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (v1[i] > v2[i]) tot += v1[i] - v2[i];
    }
    cout << tot << '\n';
    return 0;
}