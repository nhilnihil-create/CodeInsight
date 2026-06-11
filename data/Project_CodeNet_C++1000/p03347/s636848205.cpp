#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    if(a[0] != 0){ cout << -1 << endl; return 0; }

    long long int ans = 0;
    for(int i=1; i<n; i++){
        if(a[i] - a[i-1] >= 2){ cout << -1 << endl; return 0; }
        else if(a[i] - a[i-1] == 1) ans += 1;
        else ans += a[i];
    }
    cout << ans << endl;
    return 0;
}