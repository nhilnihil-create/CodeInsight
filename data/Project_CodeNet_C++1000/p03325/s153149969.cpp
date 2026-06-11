#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <long long> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        long long div = 0;
        while(a[i]%2==0){
            a[i]/=2;
            div++;
        }
        a[i] = div;
    }
    long long ans = 0;
    for(long long i = 0; i < n; i++){
        ans += a[i];
    }
    cout << ans << endl;

    return 0;
}