#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    long long center, centerL;
    cin >> num;

    vector<long long> vec(num);
    vector<long long> vec2;
    for (int i = 0; i < num; i++) { cin >> vec.at(i); }

    vec2 = vec;
    sort(vec2.begin(), vec2.end());

    center = vec2.at(num / 2);
    centerL = vec2.at(num / 2 - 1);

    for (int i = 0; i < num; i++) {
        if (vec.at(i) < center) {
            cout << center << endl;
        } else {
            cout << centerL << endl;
        }
    }
}