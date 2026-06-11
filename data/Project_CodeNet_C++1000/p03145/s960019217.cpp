#include <bits/stdc++.h>

using namespace std;


int main() {
    int ab = 0, bc = 0, ca = 0;
    cin >> ab >> bc >> ca;
    vector<int> vec;
    vec.push_back(ab);
    vec.push_back(bc);
    vec.push_back(ca);

    sort(vec.begin(), vec.end());
    cout << (vec[0] * vec[1]) / 2 << endl;
}