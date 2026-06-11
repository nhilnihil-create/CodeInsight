#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec.at(i);
    }
    int m = *min_element(vec.begin(), vec.end());
    int M = *max_element(vec.begin(), vec.end());
    cout << M - m << endl; 
}