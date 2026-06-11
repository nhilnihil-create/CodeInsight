#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> x = {1, 4, 7, 9};
    vector<int> y(4);
    for (int i = 0; i < 4; i++) cin >> y[i];
    sort(y.begin(), y.end());
    if (x == y) cout << "YES" << endl;
    else cout << "NO" << endl;
}