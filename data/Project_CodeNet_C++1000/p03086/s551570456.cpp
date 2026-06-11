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
    string s;
    cin >> s;
    int n;
    n = s.size();
    int tot = 0;
    for (int i = 0; i <= n - 1; i++) { 
        int now = 0;
        for (int j = i; j <= n - 1; j++) {
            if (s[j] == 'A' || s[j] == 'T' || s[j] == 'C' || s[j] == 'G') {
                now++;
            }
            else break;
        }
        tot = max(tot, now);
        now = 0;
    }
    cout << tot << '\n';
    return 0;
}