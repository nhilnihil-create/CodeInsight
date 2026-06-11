#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(3);
    int k;
    cin >> v[0] >> v[1] >> v[2];
    cin >> k;

    sort(v.begin(), v.end());

    for(int i=0; i<k; i++) {
        v[2] *= 2;
    }

    cout << v[0] + v[1] + v[2] << endl;
}
