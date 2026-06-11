#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

long gcd(long a, long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    long n,x;
    cin >> n >> x;
    vector <long> place(n),dec(n);
    rep(i,n){
        cin >> place[i];
        dec[i] = abs(place[i] - x);
    } 

    if(n==1){
        cout << dec[0] << endl;
        return 0;
    }

    long ans=gcd(dec[0],dec[1]);
    for(int i=0; i<n; i++){
        ans = gcd(ans,dec[i]);
    }

    cout << ans << endl;
}
