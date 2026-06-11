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
    string s;
    cin >> s;
    ll iti=0,zero=0,s_size=s.size();

    for(ll i = 0;i < s_size;i++){
        if(s.at(i) == '1')
            iti++;
        else
            zero++;
    }

    if(iti >= zero)
        cout << zero * 2 << endl;
    else
        cout << iti * 2 << endl;
}