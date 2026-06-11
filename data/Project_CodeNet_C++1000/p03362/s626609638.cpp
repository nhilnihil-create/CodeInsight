#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int x = 2; x <= 55555; x++) {
        bool flag = true;
        for (int p = 2; p * p <= x; p++) {
            if (x%p == 0)
                flag = false;
        }
        if (flag && x % 5 == 1)
            v.push_back(x);
    }

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}