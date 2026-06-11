#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    long long res=1000000000;
    for(int i=0;i<=n-k;i++){
        res=min({res,abs(a[i])+abs(a[i+k-1LL]-a[i]),abs(a[i+k-1LL])+abs(a[i+k-1LL]-a[i])});
    }
    cout << res << endl;
}