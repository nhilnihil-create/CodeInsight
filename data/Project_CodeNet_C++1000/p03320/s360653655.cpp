#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
const int MOD=1000000007;

lint S(lint a){
    lint r=0;
    while(a>0){
        r+=a%10;
        a/=10;
    }
    return r;
}
bool former(lint a, lint b){
    return (a*S(b)<b*S(a)) || (a*S(b)==b*S(a) && a<b);
}
int keta(lint a){
    int k=1;
    while(a>10){
        k++;
        a/=10;
    }
    return k;
}
lint pow10(lint n){
    if(n<=0) return 1LL;
    else return pow10(n-1)*10LL;
}

lint nextsunuke(lint n){
    lint r=n+1;
    int k=keta(n+1);
    for(lint i=0;i<=k+1;i++){
        lint m=pow10(i)*((n+1)/pow10(i)+1LL)-1;
        if(m>n){
            r=former(r,m)?r:m;
        }
    }

    return r;
}
int main(){
    int K;
    cin >> K;
    lint prev=1LL;
    cout << 1 << endl;

    for(int i=2;i<=K;i++){
        prev=nextsunuke(prev);
        cout << prev << endl;
    }
    return 0;
}