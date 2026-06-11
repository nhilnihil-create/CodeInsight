#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    ll l=pow(10,15);
    cin >> n;
    for(int i=0; i<5; i++){
        ll k;
        cin >> k;
        l=min(l,k);
    }
    ll ans;
    if(n%l==0){
        cout << n/l+4 << endl;
    }
    else{
        cout << n/l + 5 << endl;
    }
}