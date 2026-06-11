#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)

const ll MOD = pow(10, 9) + 7;

const ll MAX_N = pow(10, 10);

int main(){
    int n;
    cin >> n;
    vll D(n);
    rep(i, n) cin >> D[i];
    int m;
    cin >> m;
    vll T(m);
    rep(i, m) cin >> T[i];

    //D[i]の個数を入れるmapを作成
    map<ll, int> mapD;
    map<ll, int> mapT;

    rep(i, n){
        ll d = D[i];
        mapD[d]++;
    }
    rep(i, m){
        ll t = T[i];
        mapT[t]++;
    }

    if(m > n){
        cout << "NO" << endl;
        return 0;
    }

    rep(i, m){
        ll x = T[i];
        if(mapD[x] < mapT[x]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}