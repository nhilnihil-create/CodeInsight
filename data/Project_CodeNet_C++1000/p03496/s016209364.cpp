#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int min_a = *min_element(a.begin(), a.end());
    int max_a = *max_element(a.begin(), a.end());
    int itr_max;
    int itr_min;
    for (int i = 0; i < n; i++) {
        if (a[i] == max_a) itr_max = i;
        if (a[i] == min_a) itr_min = i;
    }
    if (min_a >= 0) {
        cout << n - 1 << endl;
        for (int i = 2; i <= n; i++) cout << i - 1 << " " << i << endl;
    }
    else if (max_a <= 0) {
        cout << n - 1 << endl;
        for (int i = n; i > 1; i--) cout << i << " " << i - 1 << endl;
    }
    else if (abs(max_a) >= abs(min_a)) {
        cout << 2*n - 2 << endl;
        for (int i = 0; i < n; i++) {
            if (itr_max != i) cout << itr_max + 1 << " " << i + 1 << endl;
        }
        for (int i = 2; i <= n; i++) cout << i - 1 << " " << i << endl;
    }
    else {
        cout << 2*n - 2 << endl;
        for (int i = 0; i < n; i++) {
            if (itr_min != i) cout << itr_min + 1 << " " << i + 1 << endl;
        }
        for (int i = n; i > 1; i--) cout << i << " " << i - 1 << endl;
    }
}
