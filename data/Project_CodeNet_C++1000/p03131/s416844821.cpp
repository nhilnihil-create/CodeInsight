#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {

    ll k,a,b; cin >> k >> a >> b;
    ll d = b-a;
    if(k < a-1){
        cout << k + 1;
    } else if(d >= 2){
        cout << b + ((k-(a-1))/2 - 1)*(b-a) + (k-(a-1))%2;
    }else{
        cout << k + 1;
    }


    return 0;
}









