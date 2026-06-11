#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

//pdf見て解答

int main(){
    ll n; cin >> n;
    ll m,a,r,c,h;
    m = a = r = c = h = 0;

    rep(i,n){
        string tmp; cin >> tmp;
        char head = tmp[0];
        if(head == 'M') m++;
        else if(head == 'R') r++;
        else if(head == 'A') a++;
        else if(head == 'C') c++;
        else if(head == 'H') h++;
    }

    ll ans = 0;
    ans += m * r * a;
    ans += m * r * c;
    ans += m * r * h;
    ans += m * a * c;
    ans += m * a * h;
    ans += m * c * h;
    ans += r * a * c;
    ans += r * a * h;
    ans += r * c * h;
    ans += a * c * h;

    put(ans);
}