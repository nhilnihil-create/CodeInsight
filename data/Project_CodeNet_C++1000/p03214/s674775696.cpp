#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        sum += a.at(i);
        a.at(i) *= n;
    }
    
    int diff = 100000000;
    int index = 0;
    
    for (int i = 0; i < n; i++) {
        if (abs(sum - a.at(i)) < diff) {
            index = i;
            diff = abs(sum - a.at(i));
        }
    }
    
    cout << index << endl;
}