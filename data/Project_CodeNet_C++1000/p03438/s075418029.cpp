#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    int n;  cin >> n;
    vector<ll> a(n), b(n);

    ll asum=0, bsum=0;
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        asum += a.at(i);
    }
    for(int i=0; i<n; i++){
        cin >> b.at(i);
        bsum += b.at(i);
    }
    string ans="No";
    ll bc=0, ac=0;
    if(asum<=bsum){
        for(int i=0; i<n; i++){
            if(a[i]<b[i]){
                ac += (b[i]-a[i])/2 + (b[i]-a[i])%2;
                bc += (b[i]-a[i])%2;;
            }else{
                bc += (a[i]-b[i]);
            }
        }
        if(bc<=ac)
            ans = "Yes";
    }
    cout << ans << endl;
}

