#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int num[n+1] = {0};
    for(int i = 0; i < n; i++){
        num[a[i]]++;
    }

    sort(num, num+n+1, greater<int>());

    // for(int i = 0; i < n+1; i++){
    //     cout << num[i] << endl;
    // }

    int ans = 0;
    for(int i = k; i < n+1; i++){
        ans += num[i];
    }

    cout << ans << endl;
}