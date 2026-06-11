#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N;
    cin >> N;
    ll out = 0;
    ll a = 0;
    ll b = 0;
    ll ab = 0;
    ll ba = 0;
    rep(i,N){
        string s;
        cin >> s;
        if(s[0]=='B') b++;
        if(s[s.size()-1]=='A') a++;
        rep(j,s.size()-1){
            if(s[j]=='A'&&s[j+1]=='B') ab++;
        }
        if(s[0]=='B'&&s[s.size()-1]=='A') ba++;
    }
    out = min(a,b)+ab;
    if(ba>0&&a==ba&&b==ba) out--;
    cout << out << endl;
    return 0;
}
