#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n,h,w;
    cin >> n >> h >> w;
    ll co=0;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        if(a>=h&&b>=w)co++;
    }
    cout << co <<endl;
    return 0;
}