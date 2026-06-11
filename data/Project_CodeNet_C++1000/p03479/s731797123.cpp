#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x, y;    cin >> x >> y;

    ll ans=0, tmp=x;
    do{
        tmp *= 2;
        ans += 1; 
    }while(tmp<=y);
    cout << ans << endl;
    

}


