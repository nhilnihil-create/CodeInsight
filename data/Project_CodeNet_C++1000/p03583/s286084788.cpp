#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;


int main() {
        ll n;
        cin >> n;
        ll a,b,c;
        ll MX = 3500;
        bool ok = false;
        for(ll h=1;h<=MX;h++){
                for(ll w=1;w<=MX;w++){
                        ll mother = 4*h*w - n*h - n*w;
                        ll kid = n*h*w;
                        if( mother * kid <= 0) continue;
                        if(kid%mother == 0){
                                a = h;
                                b = w;
                                c = kid/mother;
                                ok = true;
                        }
                        if(ok) break;
                }
                if(ok) break;
        }

        cout << a << " " << b << " " << c << endl;

        return 0;
}