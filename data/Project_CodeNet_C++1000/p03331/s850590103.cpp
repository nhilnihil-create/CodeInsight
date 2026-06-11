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

ll digitsum(ll X){
    int x=0;
    while(X > 0){
        x += X % 10;
        X/=10;
    }

    return x;

}

int main(){
    ll N,A,B,min=1000000;
    cin >> N;

    for(ll i = 1;i < N;i++){
        A = digitsum(i);
        B = digitsum(N-i);
        if(min > A+B)
            min = A+B;
    }

    cout << min <<endl; 

}