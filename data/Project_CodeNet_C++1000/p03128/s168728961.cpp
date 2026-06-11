#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a.at(i);
    }
    sort(a.rbegin(), a.rend());
    const vector<int> cost = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    vector<int> max_digit(n + 1, -1);
    max_digit.at(0) = 0;
    for (int i = 0; i < n; i++) {
        if (max_digit.at(i) == -1) continue;
        
        for (int j = 0; j < m; j++) {
            int c = cost.at(a.at(j));
            if (i + c <= n) max_digit.at(i + c) = max(max_digit.at(i + c), max_digit.at(i) + 1);
        }
    }

    int num = n;
    int d = max_digit.at(n);
    
    while (num > 0) {
        for (int i = 0; i < m; i++) {
            int c = cost.at(a.at(i));
            if (num - c < 0) continue;
            
            if (d - 1 == max_digit.at(num - c)) {
                printf("%d", a.at(i));
                num -= c;
                d--;
                break;
            }
        }
    }
    cout << endl;
}  