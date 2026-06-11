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
    ll N,K;
    cin >> N >> K;

    ll kensa = 1;

    for(int i = 0;i < 20;i++)
        kensa *= 2;

    double goukei = 0.0;
    for(ll i = 1;i <= N;i++){
        int res = 0;
        ll hako = i;
        while(hako < K){
            hako *= 2;
            res++;
        }

        double keisan = 1;
        for(int j = 0;j < res;j++){
            keisan /= 2.0;
        }

        goukei += keisan / (double)N;

    }

    printf("%.12f\n",goukei);
}