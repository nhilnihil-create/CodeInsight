#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for(int i=0; i<n; i++){
        cin >> l[i] >> r[i];
        r[i] *= -1;
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    long long int ans1 = 0, ans2 = 0, ans3 = 0, left = 0, right = 0;
    for(int i=n-1; i>=0; i--){
        ans1 = max(ans1, left + right + 2 * l[i]);
        ans2 = max(ans2, left + right + 2 * r[i]);
        left  += 2 * l[i];
        right += 2 * r[i];
        ans3 = max(ans3, left + right);
    }

    cout << max({ans1, ans2, ans3}) << endl;
    return 0;
}