#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> ad, bd;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0)
            ad.push_back(i);
    }
    for (int i = 1; i <= b; i++) {
        if (b % i == 0)
            bd.push_back(i);
    }

    ad.insert(ad.end(), bd.begin(), bd.end());
    sort (ad.begin(), ad.end());

    vector<int> cd;
    for (int i = 0; i < ad.size()-1; i++) {
        if (ad[i] == ad[i+1]) {
            cd.push_back(ad[i]);
        }
    }

    reverse(cd.begin(), cd.end());
    cout << cd[k-1] << endl;
}