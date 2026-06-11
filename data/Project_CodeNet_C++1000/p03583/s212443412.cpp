#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

/*
4/N = 1/h + 1/n + 1/w
4hnw/N = nw+hw+hn
N = 4hnw/nw+hw+hn

4hnw = w(h+n)N+hnN
w(4hn-hN-nN) = hnN

*/

int main()
{
    ll N;
    cin >> N;

    ll ans[3] = {0};
    rep1(h, 3500)rep1(n, 3500){
        ll r = h*n*N;
        ll l = (4*h*n-h*N-n*N);
        if (l<=0) continue;
        if (r%l == 0){
            ans[0] = h;
            ans[1] = n;
            ans[2] = r/l;            
            break;
        }
    }

    show(ans);
}

