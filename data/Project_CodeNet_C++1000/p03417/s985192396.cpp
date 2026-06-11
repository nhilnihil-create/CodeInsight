#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
//const int MOD = 1e9+7;

int main(){
    ll n, m;
    cin >> n >> m;

    if(n==1 && m==1){
        cout << 1;
        return 0;
    }

    if(n==1){
        cout << m-2;
        return 0;
    }
    if(m==1){
        cout << n-2;
        return 0;
    }
    cout << (n-2)*(m-2);

}
