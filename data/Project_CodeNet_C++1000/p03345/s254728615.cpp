#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    long long a,b,c,k;
    cin >> a >> b >> c >>k;
    long long ans = a-b;
    if(k%2 != 0){
        ans *= -1;
    }
    cout << ans <<endl;
}