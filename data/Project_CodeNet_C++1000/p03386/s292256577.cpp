#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b, k; cin >> a >> b >> k;

    vector<int> vec;
    for (int i = a; i <= b ; i++) {
        if (i - a + 1 <= k) vec.emplace_back(i);
        if (b - i + 1 <= k) vec.emplace_back(i);
    }
    sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    return 0;
}