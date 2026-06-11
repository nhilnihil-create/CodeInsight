#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    for (int i=0; i<n; i++) cin >> m[i];
    int sum = accumulate(m.begin(), m.end(), 0);
    sort(m.begin(), m.end());
    cout << n + (x-sum) / m[0] << endl;
    return 0;
}