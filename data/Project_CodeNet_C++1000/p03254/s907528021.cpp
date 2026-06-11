#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, cnt = 0;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        if(x - arr[i] >= 0) {
            cnt++;
            x -= arr[i];
        } else break;
    }
    if(x > 0 && cnt == n) cnt--;
    cnt = max(cnt, 0);
    cout << cnt << endl;
    return 0;
}
