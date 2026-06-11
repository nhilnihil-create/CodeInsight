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

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))


int main(){
    ll N;
    cin >> N;
    vector<ll>A(N),B(N),C(N),ruiAB(N);

    for(ll i = 0;i < N;i++)
        cin >> A.at(i);

    for(ll i = 0;i < N;i++)
        cin >> B.at(i);

    for(ll i = 0;i < N;i++)
        cin >> C.at(i);
    
    for(ll i = 0;i < N;i++)
        ruiAB.at(i) = 0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    ll res = 0,b_atai;

    for(ll i = 0;i < N;i++){
        const ll j = lower_bound(ALL(A),B.at(i)) - A.begin();
        if(i == 0)
            ruiAB.at(i) = j;
        else
            ruiAB.at(i) = j + ruiAB.at(i-1);
    }

    for(ll i = 0;i < N;i++){
        const ll j = lower_bound(ALL(B),C.at(i)) - B.begin();
        if(j == 0)
            res += 0;
        else
            res += ruiAB.at(j-1);
    }

    cout << res << endl;

}