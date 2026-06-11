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


using namespace std;

typedef long long ll;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define Rep(i, n) for(int i=n; i >= 0; i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える


int main(){
    int n; cin >> n;

    vll a(n); rep(i, n) cin >> a[i];

    vll s(n+1, 0); s[0] = 0; rep(i, n) s[i+1] = s[i] + a[i];

    map<ll, ll> mp;

    mp[s[0]]++;
    rep(i, n) mp[s[i+1]]++;

    ll cnt = 0;
    for(auto m: mp) cnt += m.second * (m.second-1)/2;

    cout << cnt << endl;
}