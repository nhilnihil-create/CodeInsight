#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;

    cin >> num;

    vector<long long> vec(num);
    for (int i = 0; i < num; i++) cin >> vec.at(i);

    sort(vec.begin(), vec.end());

    cout << vec.at(num - 1) - vec.at(0);
}
