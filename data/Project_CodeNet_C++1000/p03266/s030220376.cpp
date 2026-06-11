#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; i++) 

int main() {
    long long int n, k;
    cin >> n >> k;

    long long int cnt = 0;

    for (long long int a = 1; a <= n; a++){
        long long int t = a % k;
        
        if(2*(k-t)%k==0){
            long long int m = (n - k + t) / k + 1;
            cnt += m * m;
        }
    }

    cout << cnt << endl;
}