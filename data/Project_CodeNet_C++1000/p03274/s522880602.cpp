#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n, k;   cin >> n >> k;
    vector<ll> x(n, 0);
    for(int i=0; i<n; i++) cin >> x.at(i);

    ll ans=1e+15;
    for(int i=0; i<n-k+1; i++){
        ll a = x.at(i), b=x.at(i+k-1), tmp;
        if(b<=0) tmp = abs(x.at(i));
        else if(0<=a)   tmp = x.at(i+k-1);
        else tmp = min(abs(x.at(i)*2)+x.at(i+k-1), abs(x.at(i))+2*x.at(i+k-1));

        ans = min(ans, tmp);
    }
    
    cout << ans << endl;

}