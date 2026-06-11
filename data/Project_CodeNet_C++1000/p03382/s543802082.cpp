#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int max = *max_element(a.begin(), a.end());
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(abs(2*a[i]-max) < abs(2*ans-max)) ans = a[i];
    }

    cout << max << ' ' << ans << endl;
    return 0;
}
