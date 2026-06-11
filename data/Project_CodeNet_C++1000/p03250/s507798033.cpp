#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    vector<int> vec(3);
    cin >> vec[0];
    cin >> vec[1];
    cin >> vec[2];

    sort(vec.begin(),vec.end());

    cout << 10*vec[2]+vec[1]+vec[0] << endl;
}
