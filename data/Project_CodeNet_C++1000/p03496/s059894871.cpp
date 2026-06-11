#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    pair<int, int> maximum = make_pair(-1000001, 0);
    pair<int, int> minimum =  make_pair(1000001, 0);
    bool is_plus = true;
    bool is_minus = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);

        if (a.at(i) > 0) is_minus = false;
        if (a.at(i) < 0) is_plus = false;

        if (a.at(i) > maximum.first) maximum = make_pair(a.at(i), i + 1);
        if (a.at(i) < minimum.first) minimum = make_pair(a.at(i), i + 1);
    }
    
    if (is_plus) {
        cout << n - 1 << endl;
        for (int i = 2; i <= n; i++)
        {
            printf("%d %d\n", i - 1, i);
        }

        return 0;
    }
    
    if (is_minus) {
        cout << n - 1 << endl;
        for (int i = n; i >= 2; i--)
        {
            printf("%d %d\n", i, i - 1);
        }
        
        return 0;
    }

    if (abs(maximum.first) >= abs(minimum.first)) {
        cout << n * 2 - 2 << endl;
        for (int i = 1; i <= n; i++)
        {
            if (i != maximum.second) printf("%d %d\n", maximum.second, i);
        }
        for (int i = 2; i <= n; i++)
        {
            printf("%d %d\n", i - 1, i);
        }
    }
    else {
        cout << n * 2 - 2 << endl;
        for (int i = 1; i <= n; i++)
        {
            if (i != minimum.second) printf("%d %d\n", minimum.second, i);
        }
        for (int i = n; i >= 2; i--)
        {
            printf("%d %d\n", i, i - 1);
        }
    }
}
