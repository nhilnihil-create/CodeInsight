#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    if (a%b == 0) return(b);
    else return(gcd(b, a%b));
}

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int s;
        cin >> s;
        a[i]=abs(s-x);
    }

    if(n==1){
        cout << a[0] << endl;
        return 0;
    }

    int ans = gcd(a[0],a[1]);
    for(int i = 2; i < n; i++) {
        ans = gcd(ans,a[i]);
    }

    cout << ans << endl;

    return 0;
}