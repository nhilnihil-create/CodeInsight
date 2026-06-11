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
    int N,T,min=10000;
    cin >> N >> T;
    vector<int>c(N),t(N);
    bool fla = false;

    for(ll i = 0;i < N;i++){
        cin >> c.at(i) >> t.at(i);
    }

    for(ll i = 0;i < N;i++){
        if(t.at(i) <= T){
            if(min > c.at(i))
                min = c.at(i);
            fla = true;
        }
    }

    if(fla)
        cout << min << endl;
    else
        cout <<"TLE"<< endl;

}