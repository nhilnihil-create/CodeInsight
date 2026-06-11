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

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    ll N,M,sum=0;
    cin >> N >> M;

    vector<ll> X(M),sa(M-1);

    for(ll i = 0;i < M;i++)
        cin >> X.at(i);

    sort(X.begin(),X.end());

    for(ll i = 0;i < M - 1;i++)
        sa.at(i) = abs(X.at(i) - X.at(i+1));

    sort(sa.begin(),sa.end());

    if(M> N)
        for(ll i = 0;i < M - N;i++)
            sum += sa.at(i);

    cout << sum << endl;




    
    
}