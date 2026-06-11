#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    ll r, d, x2000;
    cin >> r >> d >> x2000;
    for(int i = 1; i <= 10; i++){
        x2000 = r * x2000 - d;
        cout << x2000 << endl;
    }
    return 0;
}
