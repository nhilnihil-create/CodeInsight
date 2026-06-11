#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#include <set>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define SORT(s) sort((s).begin(),(s).end())

int main(){
    ll N,M,X,Y; cin >> N >> M >> X >>Y;
    vector<ll> x(N); REP(i,N) cin >> x[i];
    vector<ll> y(M); REP(i,M) cin >> y[i];

    ll max_x = *max_element(x.begin(),x.end());
    ll min_y = *min_element(y.begin(),y.end());
    bool ans = false;
    FOR(Z,X+1,Y){
        if(max_x<Z && min_y>=Z){
            ans = true;
        }
    }

    if(ans) cout << "No War" << endl;
    else cout << "War" << endl;
}
