#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n+1];
    int m = 0, p = -1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(abs(a[i]) >= abs(m)) {
            m = a[i];
            p = i;
        }
    }
    cout << 2*n-1 << endl;
    if(m >= 0){
        for(int i = 1; i <= n; i++) cout << p << " " << i << endl;
        for(int i = 1; i < n; i++) cout << i << " " << i+1 << endl;
    } else {
        for(int i = 1; i <= n; i++) cout << p << " " << i << endl;
        for(int i = n; i >= 2; i--) cout << i << " " << i-1 << endl;
    }
    return 0;
}