#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;


ll gcd(ll a, ll b) {
    if(a < b) return gcd(b, a);
    ll r;
    while ((r=a%b)) {
      a = b;
      b = r;
    }
    return b; //あまりが0ならそれが、最大公約数
}
//あまりが0になるまで a%b (a > bとする)
//あまりが0でなければ(あまりをrとし)、a = b; b = r         bと割ったあまり で　b%r する

ll lcm(ll a, ll b) {
    ll g = gcd(a,b);
    return a*b/g;
}

int main(){
    //N:sの最初の長さ
    ll N,M;
    cin >> N >> M;
    string s,t;
    cin >> s >> t;

    ll l = lcm(N,M);
    // l = a * N; 
    // l = b * M; 
    ll a = l / N;
    ll b = l / M;

    ll l2 = lcm(a,b);

    for(int i = 0; i < l / l2; ++i)
    {
        if(s[i * l2 / a] != t[i * l2 / b])
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << l << endl;

    return 0;    
}

