#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i;
    long long arr[90] = {0};
    arr[0] = 2;
    arr[1] = 1;
    for(i=2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n] << endl;
    return 0;
}