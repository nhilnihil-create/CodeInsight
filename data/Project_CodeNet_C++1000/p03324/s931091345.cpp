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
    int N,D;
    cin >> D >> N;

    if(D == 0){
        int k = 0;
        for(int i = 0;i < N;i++)
            k++;
        if(N == 100)
            cout << 101 << endl;
        else
            cout << k << endl;
    }else if(D == 1){
        int k = 0;
        for(int i = 0;i < N;i++)
            k+=100;
        if(N == 100)
            cout << 10100 << endl;
        else
            cout << k << endl;
    }else{
        ll k = 0;
        for(int i = 0;i < N;i++)
            k += 10000;
        if(N == 100)
            cout << 101 * 10000 << endl;
        else
            cout << k << endl;
    }

}