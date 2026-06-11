#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    ll k, a, b; cin >> k >> a >> b;
    if(b-a<=2){
        cout << k+1 << endl;
        return 0;
    }

    if(k<a){
        cout << k+1 << endl;
    }else{
        ll num = k - (a-1);
        ll tmp = num/2;
        if(num%2==0){
            cout << a + (b-a)*tmp << endl;
        }else{
            cout << a + (b-a)*tmp + 1 << endl;
        }
    }
}