#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int ans = 1000000000;
    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(ans > abs(sum - a[i] * n)){
            ans = abs(sum - a[i] * n);
            tmp = i;
        }
    }
    cout << tmp << endl;

    return 0;
}
