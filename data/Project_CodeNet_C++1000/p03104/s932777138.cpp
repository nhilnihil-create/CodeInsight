#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using P = pair<int,ll>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

ll binary(ll bina){
    ll ans = 0;
    for (ll i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}


int main()
{
    ll A,B;
    cin >> A >> B;

    ll C,D;
    bool a = false;
    bool b = false;
    if(A%2 == 1){//奇数
        a = true;
        C = A + 1;
    }
    if(B%2 == 0){//偶数
        b = true;
        D = B - 1;
    }

    ll ans;
    ll c;    
    if(a&&b){
        c = (B - A - 1)/2;
        if(c%2 == 0) ans = A^B;
        else ans = A^1^B;        
    }
    else if(a&&!b){
        c = (B - A)/2;
        if(c%2 == 0) ans = A + 0;
        else ans = A^1;        
    }
    else if(!a&&b){
        c = (B - A)/2;
        if(c%2 == 0) ans = B + 0;
        else ans = B^1;        
    }
    else{
        c = (B - A + 1)/2;
        if(c%2 == 0) ans = 0;
        else ans = 1;
    }

    cout << ans << endl;

    return 0;
}
//Ctrl+Shift+Bでコンパイルと実行を行ってデバッグすること