#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)


int main(){
    ll a, b;
    int k; cin >> a >> b >> k;
    rep(i,k){
        if(i%2){ //青木君
            if(b%2) b -= 1;
            b /= 2;
            a += b;
        }else{ //高橋君
            if(a%2) a -= 1;
            a /= 2;
            b += a;
        }
    }
    cout << a << " " << b << endl;
}