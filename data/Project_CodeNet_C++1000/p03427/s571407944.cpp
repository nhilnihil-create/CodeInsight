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
#include <iostream>

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
    string N;
    cin >> N;

    int s = N.size();
    int res2=0;
    bool fla = true;

    for(int i = 0;i < s-1;i++)
        res2 += 9;

    for(int i = 1;i < s;i++){
        if(N.at(i) != '9')
            fla = false;
    }

    if(fla){
        res2 += int(N.at(0)) -48;
    }else{
        res2 += int(N.at(0)) -49;
    }

    cout << res2 << endl;

    
}