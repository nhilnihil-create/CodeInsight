#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

/*
0のアスキー　"48"
*/

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

ll ninokosu(ll X){
    ll c = 0;
    while(X % 2 == 0){
        X /= 2;
        c++;
    }
    return c;
}

int main(){
    ll N;
    cin >> N;
    vector<ll>A(N);
    for(ll i = 0;i < N;i++)
        cin >> A.at(i);
    ll res = 0;

    for(ll i = 0;i < N;i++){
        res += ninokosu(A.at(i));
    }

    cout << res << endl;
}





    