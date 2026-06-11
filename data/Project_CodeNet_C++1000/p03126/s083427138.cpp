#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a[n];
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        for (int j=0; j<k; j++) {
            int u;
            cin >> u;
            a[i].push_back(u);
        }
    }
    int check[m+1] = {0};
    for (int i=0; i<n; i++) {
        for (auto x: a[i]) {
            check[x]++;
        }
    }
    int cnt = 0;
    for (int i=1; i<=m; i++) {
        if (check[i] == n) cnt++;
    }
    cout << cnt << '\n';
    
    return 0;
}