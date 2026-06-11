#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for (auto& i:a) cin >> i;
    int sum = accumulate(a.begin(),a.end(),0);
    for (int j=0;j<n;j++) {
        b[j] = abs(sum-n*a[j]);
    }
    auto pos = min_element(b.begin(),b.end());
    cout << distance(b.begin(),pos) << endl;
    return 0;
}