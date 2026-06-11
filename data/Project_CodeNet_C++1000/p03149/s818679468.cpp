#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> a = {1, 4, 7, 9};
    vector<int> v(4);
    for(int i = 0; i < 4; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(a == v) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}