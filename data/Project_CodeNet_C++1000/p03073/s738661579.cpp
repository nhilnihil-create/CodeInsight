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
    int n = 0;
    string s;
    cin >> s;
    string s1 = "";
    string s2 = "";
    n = s.size();
    for (int i = 0; i <= n - 1; i++) {
        if (i % 2 == 0) {
            s1 += '0';
            s2 += '1';
        }
        else {
            s1 += '1';
            s2 += '0';
        }
    }
    int m1 = 0;
    int m2 = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (s[i] != s1[i]) m1++;
        if (s[i] != s2[i]) m2++;
    }
    cout << min(m1, m2) << '\n';
    return 0;
}