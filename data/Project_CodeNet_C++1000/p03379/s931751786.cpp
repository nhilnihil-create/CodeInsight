#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n+10), y(n+10);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        y[i] = x[i];
    }
    sort(y.begin(), y.begin() + n);

    int m_idx = n / 2;
    
    for (int i = 0; i < n; i++) {
        if (x[i] >= y[m_idx]) cout << y[m_idx - 1] << endl;
        else cout << y[m_idx] << endl;
    }

}