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
    int N,ans = 0;
    cin >> N;

    vector<int> V(N+10),C(N+10);

    for(int i = 0;i < N;i++){
        cin >> V.at(i);
    }

    for(int i = 0;i < N;i++)
        cin >> C.at(i);

    for(int i = 0;i < N;i++){
        if(V.at(i) > C.at(i))
            ans += V.at(i) - C.at(i);
    }

    cout << ans << endl;




}