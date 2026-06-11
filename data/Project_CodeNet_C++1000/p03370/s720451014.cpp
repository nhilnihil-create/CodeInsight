#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    int minM = 10000;
    for (int i=0; i<n; i++) {
        cin >> v.at(i);
        minM = min(minM, v.at(i));
        m -= v.at(i);
    }
    
    cout << v.size() + m / minM << endl;
    
    
}