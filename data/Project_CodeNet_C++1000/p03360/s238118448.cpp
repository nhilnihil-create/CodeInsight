#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll arr[3], k;
    cin >> arr[0] >> arr[1] >> arr[2] >> k;
    sort(arr, arr + 3);
    cout << arr[2] * (2 << (k - 1)) + arr[1] + arr[0];
    return 0;
}
