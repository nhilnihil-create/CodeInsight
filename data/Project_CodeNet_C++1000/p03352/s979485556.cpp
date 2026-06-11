#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, ans = 1;
    cin >> x;
    vector<int> v;
    v.push_back(1);
    for(int i = 2; i <= x; i++) {
        for(int j = 2; j <= 10; j++) {
            if(pow(i, j) <= x) v.push_back(pow(i, j));
            else break;
        }
    }
    sort(v.begin(), v.end());
    cout << v.back() << '\n';

    return 0;
}
