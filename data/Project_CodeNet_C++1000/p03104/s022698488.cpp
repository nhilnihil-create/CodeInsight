#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b;
    cin >> a >> b;
    if(a==b){
        cout << a << endl;
        return 0;
    }
    ll res;
    if(a%2==0){
        ll n=b-a+1;
        if(n%4==0) res=0;
        else if(n%4==2) res=1;
        else if(n%4==1) res=b;
        else if(n%4==3) res=1^b;
    }
    else{
        ll n=b-a;
        if(n%4==0) res=a;
        else if(n%4==2) res=a^1;
        else if(n%4==1) res=a^b;
        else if(n%4==3) res=a^1^b;
    }
    cout << res << endl;
    return 0;
}
