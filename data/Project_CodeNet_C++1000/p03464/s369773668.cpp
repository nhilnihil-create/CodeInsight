#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
   
    ll r  = ll(1e18)+5;
    
    ll l = 0;
    while(l+1 <r){
        ll mid = (r+l)/2;
        ll num = mid;
        for(int i=0;i<N;i++){
            num -= num%A[i];
        }
        if(num>2){
            r = mid;
        }else{
            l = mid;
        }
    }
    ll num = r-1;
    for(int i=0;i<N;i++){
        num -= num%A[i];
    }
    if(num != 2){
        cout << -1 <<endl;
        return 0;
    }
    ll large = r-1;
    r = large;
    l = 0;
    while(l + 1 < r){
        ll mid = (r+l)/2;
        // cerr <<"mid=" << mid << endl;
        ll num = mid;
        bool ok = true;
        for(int i=0;i<N;i++){
            // cerr <<"num=" <<num << endl; 
            if(num < A[i]){
                ok = false;
                break;
            }
            num = (num/A[i]) *A[i];
        }
        if(ok){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << " "<<large << endl;
    return 0;
}