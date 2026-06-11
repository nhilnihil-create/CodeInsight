#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    vector<int> num = {a + b,a - b,a * b};
    sort(num.begin(),num.end());
    cout << num.at(2) << endl;
}