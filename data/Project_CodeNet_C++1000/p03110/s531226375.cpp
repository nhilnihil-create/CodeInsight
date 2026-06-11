#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int N; cin>>N;
    double sum = 0;
    rep(i, N){
        double x;
        string u;
        cin>>x>>u;
        if(u == "BTC")
            x *= 380000;
        sum += x;
    }

    cout << fixed << setprecision(5) << sum << endl;
}
