#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    rep(i, n) {
        scanf("%d", &vec[i]);
    }

    vector<int> even(100010), odd(100010);
    rep(i, n) {
        if(i % 2 == 0) even[vec[i]]++;
        else odd[vec[i]]++;
    }

    int max_even = max_element(even.begin(), even.end()) - even.begin();
    int max_odd = max_element(odd.begin(), odd.end()) - odd.begin();

    int ans = 0;
    if(max_even != max_odd) {
        ans = (n / 2 - even[max_even]) + (n / 2 - odd[max_odd]);
        printf("%d\n", ans);
    }
    else {
        // sort(even.rbegin(), even.rend());
        // sort(odd.rbegin(), odd.rend());
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        ans = min((n / 2 - even[0]) + (n / 2 - odd[1]), (n / 2 - even[1]) + (n / 2 - odd[0]));
        printf("%d\n", ans);
    }
    return 0;
}