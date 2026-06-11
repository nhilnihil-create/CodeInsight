#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k;
    cin >> n >> k;
    // a % b >= k
    // --> k+1 <= a, b <= n

    if(k == 0){
        cout << n * n << endl;
        return 0;
    }

    long long int count = 0;
    for(int b=k+1; b<=n; b++){
        // 0 * b + k  ~  0 * b + (b-1)
        // 1 * b + k  ~  1 * b + (b-1)
        // ...
        // n/b * b + k  ~  n
        count += n/b * ((b - 1) - k + 1) + max((n - (n/b * b + k) + 1),0LL);
    }
    cout << count << endl;
    return 0;
}