#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void printArray(ll A[], int size) {
    for (int i = 0; i <= size - 1; i++) cout << A[i] << ' ';
}

int main() {
    char c;
    cin >> c;
    if (c == 'A') cout << 'T';
    else if (c == 'T') cout << 'A';
    else if (c == 'C') cout << 'G';
    else cout << 'C';
    return 0;
}