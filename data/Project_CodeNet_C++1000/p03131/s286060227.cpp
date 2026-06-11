#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll K,A,B;
    cin >> K >>A >> B;
    if(A>=K || B-A<=2){
        cout << K+1 << endl;
        return 0;
    }

    ll ans =1;
    ans += A-1;

    if((K-A+1)%2==0){
        ans += (B-A)*(K-A+1)/2;
    }else{
        ans++;
        ans += (B-A)*(K-A)/2;
    }
    cout << ans << endl;


    
    return 0;
}