#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int a, b, k;
    vector<int> vecA;
    vector<int> vecB;

    cin >> a >> b >> k;

    for (int i = 1; i <= a; i++) {
        if (a % i == 0) vecA.push_back(i);
    }

    for (int i = 1; i <= b; i++) {
        if (b % i == 0) vecB.push_back(i);
    }

    vector<int> kekka;
    for (int i = 0; i < vecA.size(); i++) {
        auto exists = find(vecB.begin(), vecB.end(), vecA.at(i)) != vecB.end();
        if (exists == true) kekka.push_back(vecA.at(i));
    }

    sort(kekka.rbegin(), kekka.rend());

    cout << kekka.at(k - 1);
    //
}
