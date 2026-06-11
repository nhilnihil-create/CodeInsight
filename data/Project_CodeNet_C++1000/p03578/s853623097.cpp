#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;   cin >> n;
    map<ll, ll> d;
    ll x;  
        for(int i=0; i<n; i++){
            cin >> x;
            d[x] += 1;
        }
    int m;  cin >> m;
    string ans="YES";
        for(int i=0; i<m; i++){
            cin >> x;
            if(d[x]<1){
                ans = "NO";
                break;
            }
            d[x] -= 1;
        }
    cout << ans << endl;
}
