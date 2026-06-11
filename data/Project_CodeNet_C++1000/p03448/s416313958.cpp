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
    int A,B,C,X,goukei;
    cin >> A >> B >> C >> X;
    ll rs = 0;

    for(int i = 0;i <= A;i++)
        for(int j = 0;j <= B;j++)
            for(int k = 0;k <= C;k++){
                if(X == 500 * i + 100 * j + 50 * k)
                    rs++;
            }

    cout << rs << endl;

    

}