#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll x, ll y){
    if(x < y) return gcd(y, x);
    if(x%y == 0) return y;
    return gcd(y, x%y);
}

int main(){
    int n;
    cin >> n;
    vector<int>c(n-1);
    vector<int>s(n-1);
    vector<int>f(n-1);
    for(int i=0;i<(n-1);i++) cin >> c[i] >> s[i] >> f[i];

    for(int i=0;i<(n-1);i++){
        int ans = 0;
        ans += s[i] + c[i];
        for(int j=i+1;j<(n-1);j++){
            while(ans%f[j] != 0) ans++;
            ans = max(ans + c[j], s[j] + c[j]);
        }
        cout << ans << endl;
    }
    cout << "0"<<endl;
}
