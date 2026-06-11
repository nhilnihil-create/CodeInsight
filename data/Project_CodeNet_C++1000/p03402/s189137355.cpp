#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

ll N=100,A,B;
char ans[100][100];

signed main() {
    cin>>A>>B;
    A--;
    B--;
    rep(y,0,100){
        rep(x,0,50)   ans[y][x]='.';
        rep(x,50,100) ans[y][x]='#';
    }

    for(ll y=0; y<100; y+=2){
        for(ll x=0; x<48; x+=2){
            if (B>0){
                ans[y][x]='#';
                B--;
            }
        }
    }

    for(ll y=0; y<100; y+=2){
        for(ll x=52; x<100; x+=2){
            if (A>0){
                ans[y][x]='.';
                A--;
            }
        }
    }

    cout<<"100 100"<<endl;
    rep(y,0,100){
        rep(x,0,100){
            cout<<ans[y][x];
        }
        cout<<endl;
    }
    return 0;
}
