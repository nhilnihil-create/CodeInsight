#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    vector<int> a0(100010, 0), a1(100010, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i % 2 == 0) a0[a[i]]++;
        else a1[a[i]]++;
    }
    int c = max_element(a0.begin(), a0.end()) - a0.begin();
    int b = max_element(a1.begin(), a1.end()) - a1.begin();
    sort(a0.begin(), a0.end());
    sort(a1.begin(), a1.end());
    if(c == b) {
        cout << min(n - a0[100009] - a1[100008], n - a1[100009] - a0[100008]) << endl;
            return 0;
    }
    else cout << n - a0[100009] - a1[100009] << endl;
    return 0;
}
