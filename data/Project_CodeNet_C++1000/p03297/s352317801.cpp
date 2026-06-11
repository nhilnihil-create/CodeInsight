#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b){
    if(a<b) return gcd(b,a);
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        ll A,B,C,D;
        cin >> A >> B >> C >> D;
        if(B>A || B>D){
            cout << "No" << endl;
            continue;
        }
        if(C>=B || A<=C){
            cout << "Yes" << endl;
            continue;
        }
        ll g=gcd(B,D);
        if((A-C)/g-(A-B)/g > 1 || ((A-C)/g-(A-B)/g==1) && (A-C)%g!=0){
            cout << "No" << endl;
            continue;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}