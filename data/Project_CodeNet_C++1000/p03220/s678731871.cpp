#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>

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
    int N,T,A;
    cin >> N >> T >> A;
    vector<ll> H(N);

    for(int i = 0;i < N;i++)
        cin >> H.at(i);
    
    int ans = 0;
    double mini = 1000000.0,hyoukou;

    for(int i = 0;i < N;i++){
        hyoukou = T - H.at(i) * 0.006;
        if(abs(A - hyoukou) < mini){
            mini = abs(A - hyoukou);
            ans = i;
        }
    }

    cout << ans + 1 << endl;

}