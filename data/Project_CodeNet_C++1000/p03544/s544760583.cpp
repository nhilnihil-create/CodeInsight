#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>

int main(){
    int n;
    cin >> n;
    ll a=2, b=1, c;

    if(n==1){
        cout << 1; 
        return 0;
    }

    for(ll i=2; i<=n; ++i){
        c=a+b;
        a = b;
        b = c;
    }

    cout << c;
}
