#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, d, x;
    cin >> n >> d >> x;

    long long a[n];

    for(long long i = 0; i < n; i++) cin >> a[i];

    long long ans = x;

    for(long long i = 0; i < n; i++){
        long long cnt = 0;
        long long start = 1;

        while(start <= d){
            start += a[i];
            cnt++;
        }
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}