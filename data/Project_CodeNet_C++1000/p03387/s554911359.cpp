#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    int count = 0;
    count += v[2]-v[1];
    v[0] += count;
    if ((v[2]-v[0])%2 == 0) {
        count += (v[2]-v[0])/2;
    } else {
        count += (v[2]-v[0])/2 + 2;
    }
    cout << count << endl;
}