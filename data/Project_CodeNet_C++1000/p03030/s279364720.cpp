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

    string S;
    ll P;
    vector<pair<string, pair<ll, ll> > > p;
    rep(i, N){
        cin >> S >> P;
        p.push_back(make_pair(S, make_pair(-P, i + 1)));
    }
    sort(p.begin(), p.end());

    rep(i, N){
        cout << p[i].second.second << endl;
    }

    return 0;
}