#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n; cin >> n;
    for(ll b=1;b<=3500;b++){
        for(ll c=1;c<=3500;c++){
            long double bo = 4*b*c - n*c - n*b;
            if(bo == 0) continue;
            long double si = n*b*c;
            long double a = si/bo;
            if(floor(a) == a && a>0){
                cout << (ll)a << " " << b << " " << c ;
                return 0;
            }
        }
    }
} 