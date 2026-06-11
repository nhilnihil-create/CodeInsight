#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N;
    cin >> N;

    ll alp[26];
    ll count[26];
    rep(i, 26){
        alp[i] = 0;
        count[i] = 0;
    }

    string S;
    cin >> S;
    rep(i, S.size()){
        alp[S[i] - 'a']++;
    }

    ll bothExist = 0;
    ll ans = 0;
    rep(i, S.size()){
        count[S[i] - 'a']++;
        if(count[S[i] - 'a'] == 1){
            bothExist++;
        }
        if(count[S[i] - 'a'] == alp[S[i] - 'a']){
            bothExist--;
        }
        ans = max(ans, bothExist);
    }

    cout << ans << endl;

    return 0;
}