#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main() {
    int a,b;
    cin >>a>>b;
    if(a>b) swap(a,b);

    if (b==1) {cout <<1 << endl;
    return 0;}
    if (a==1) {cout << b-2 << endl; 
    return 0;}
    
    ll ans = (ll)(a-2)*(b-2);
    cout << ans << endl;
    return 0;

}